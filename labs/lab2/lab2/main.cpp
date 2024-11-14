#include <iostream>
#include <cmath>

using namespace std;
void get_weight(int &pounds, double &ounces);
void convert_weight(int pounds, double ounces, int &kilograms, double &grams);
void output_metric_weight(int pounds, double ounces, int kilograms, double grams);

int main(int argc, const char * argv[])
{
    int pounds;
    double ounces;
    
    get_weight(pounds, ounces);
    return 0;
}

void get_weight(int &pounds, double &ounces)
{
    int kilograms;
    double grams;
    
    cout << "Enter the number of pounds: ";
    cin >> pounds;
    while (pounds < 0)
    {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin >> pounds;
    }
    
    cout << "Enter the number of ounces: ";
    cin >> ounces;
    while (ounces < 0)
    {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin >> ounces;
    }
    
    convert_weight(pounds, ounces, kilograms, grams);

}

void convert_weight(int pounds, double ounces, int &kilograms, double &grams)
{
    double imperial_weight;
    double metric_weight;
    
    imperial_weight = pounds + ounces/16.0;
    metric_weight = imperial_weight * 0.45359237;
    
    kilograms = floor(metric_weight);
    grams = (metric_weight - kilograms) * 1000;
    
    output_metric_weight(pounds, ounces, kilograms, grams);
}

void output_metric_weight(int pounds, double ounces, int kilograms, double grams)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    cout << pounds << " pounds and " << ounces << " ounces  converts to " << kilograms << " kilograms and " << grams << " grams" << endl;
}
