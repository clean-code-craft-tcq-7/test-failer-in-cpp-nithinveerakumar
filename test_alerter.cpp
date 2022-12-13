#include "alerter.cpp"
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

int main() {
    int (*networkAlerterstub) (float) = &networkAlertStub;
    alertInCelcius(400.5,networkAlerterstub); // above threshold
    assert(alertFailureCount==1);
    alertInCelcius(392,networkAlerterstub);//  threshold
    assert(alertFailureCount==1);
    alertInCelcius(303.6,networkAlerterstub);// below threshold
    assert(alertFailureCount==1);
    alertInCelcius(500.5,networkAlerterstub); // above threshold
    assert(alertFailureCount==2);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
