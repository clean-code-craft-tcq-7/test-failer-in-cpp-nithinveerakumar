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


void alertInCelcius(float farenheit,bool isTestEnvironment=false) {
    float celcius = (farenheit - 32) * 5 / 9; 
    int returnCode;
    if (isTestEnvironment) {
        returnCode = networkAlertStub(celcius);
    }
    else {
        returnCode=networkAlert(celcius);
    }
    if(returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5,true);
    assert(alertFailureCount==0);
    alertInCelcius(303.6,true);
    assert(alertFailureCount==1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
