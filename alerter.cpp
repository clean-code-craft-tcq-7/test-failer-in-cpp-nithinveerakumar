#include <iostream>
#include <assert.h>
int alertFailureCount = 0;
//dummy of actual production function 
int networkAlert(float celcius){
    std::cout << "[PROD]ALERT: Temperature is " << celcius << " celcius.\n";
    return 0;
}

int networkAlertStub(float celcius) {
    std::cout << "[STUB]ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius>200) {
        return 500;
    }
    return 200;
}


void alertInCelcius(float farenheit,int (*networkAlerter) (float) =&networkAlert ) {
    float celcius = (farenheit - 32) * 5 / 9; 
    int returnCode;
    returnCode = networkAlerter(celcius);
    if(returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    int (*networkAlerterstub) (float) = &networkAlertStub;
    alertInCelcius(400.5,networkAlerterstub); // above threshold
    assert(alertFailureCount==1);
    alertInCelcius(392,networkAlerterstub);//  threshold
    assert(alertFailureCount==1);
    alertInCelcius(303.6,networkAlerterstub);// below threshold
    assert(alertFailureCount==1);
    alertInCelcius(500.5,networkAlerterstub); // above threshold
    assert(alertFailureCount=2);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
