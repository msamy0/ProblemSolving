//Authour : @samy

#include <iostream>
#include <algorithm>

// creating struct that holds the traffics data
struct traffics_data {
    double golden_gate;
    double bay_bridge;
    double san_mateo;
};

//using namespace std for cout and cin
using namespace std;

int main() {
    //declaring constants and variables
    const int MONTHS_COUNT = 3;

    //creating an array of structs
    traffics_data traffics[MONTHS_COUNT];

    //declaring variables for total and highest traffic count
    double total_golden_gate = 0.0;
    double total_bay_bridge = 0.0;
    double total_san_mateo = 0.0;
    double highest_traffic_count = 0.0;

    //using for loop to get the traffics data from the user
    for (int i = 0; i < MONTHS_COUNT; i++) {
        cout << "Enter month " << i + 1 << " traffic across the Golden Gate Bridge: ";
        cin >> traffics[i].golden_gate;

        cout << "Enter month " << i + 1 << " traffic across the Bay Bridge: ";
        cin >> traffics[i].bay_bridge;

        cout << "Enter month " << i + 1 << " traffic across the San Mateo Bridge: ";
        cin >> traffics[i].san_mateo;

        //accumulating the total traffic count
        total_golden_gate += traffics[i].golden_gate;
        total_bay_bridge += traffics[i].bay_bridge;
        total_san_mateo += traffics[i].san_mateo;

        //using max function to get the highest traffic count
        highest_traffic_count = max(traffics[i].golden_gate, traffics[i].bay_bridge);
        highest_traffic_count = max(highest_traffic_count, traffics[i].san_mateo);
        
    }

    //calculating the average traffic count
    double avgGoldenGate = total_golden_gate / MONTHS_COUNT;
    double avgBayBridge = total_bay_bridge / MONTHS_COUNT;
    double avgSanMateo = total_san_mateo / MONTHS_COUNT;

    //displaying the results as required
    cout << "Average monthly traffic for Golden Gate Bridge: " << avgGoldenGate << std::endl;
    cout << "Average monthly traffic for Bay Bridge: " << avgBayBridge << std::endl;
    cout << "Average monthly traffic for San Mateo Bridge: " << avgSanMateo << std::endl;
    cout << "Highest traffic count in any one month: " << highest_traffic_count << std::endl;

    return 0;
}
