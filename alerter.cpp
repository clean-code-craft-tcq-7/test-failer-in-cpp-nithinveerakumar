#include <iostream>
#include <assert.h>
int alertFailureCount = 0;
//dummy of actual production function 
int networkAlert(float celcius){
    std::cout << "[PROD]ALERT: Temperature is " << celcius << " celcius.\n";
    return 0;
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

