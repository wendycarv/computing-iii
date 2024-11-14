#include <iostream>
using namespace std;

//clearkeyboardbuffer
class Mass{
public:
    //mutators
    void setMassAvoirdupoisPounds(double value);
    void setMassTroyPounds(double value);
    void setMassMetricGrams(double value);
    
    //accessors
    double getMassAvoirdupoisPounds(void) const;
    double getMassTroyPounds(void) const;
    double getMassMetricGrams(void) const;
private:
    double avoirdupoisPounds;
    double troyPounds;
    double grams;
    double drams;
};

double const GRAMS = 1.7718451953125;
double const AVOIRDUPOISPOUNDS = static_cast<double>(1)/256;
double const TROYPOUNDS = static_cast<double>(1)/96;

int main(int argc, const char * argv[]) {

    int input;
    double value;
    Mass weight;
    
    double AvoirdupoisPounds;
    double TroyPounds;
    double grams;
    
    cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
    
    cin >> input;
        
    while (input > 3 || input < 0)
    {
        cout << endl;
        
        cout << "That input is invalid. Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
    }
    
    if (input == 1){
        cout << "Please enter a mass in Avoirdupois pounds: ";
        cin >> value;
        weight.setMassAvoirdupoisPounds(value);
        
    } else if (input == 2){
        cout << "Please enter a mass in Troy pounds: ";
        cin >> value;
        weight.setMassTroyPounds(value);
        
    } else if (input == 3){
        cout << "Please enter a mass in grams: ";
        cin >> value;
        weight.setMassMetricGrams(value);
        
    } else {
        exit(1);
    }
    
    AvoirdupoisPounds = weight.getMassAvoirdupoisPounds();
    TroyPounds = weight.getMassTroyPounds();
    grams = weight.getMassMetricGrams();
    
    cout << "Mass in Avoirdupois pounds is " << AvoirdupoisPounds << endl;
    cout << "Mass in Troy pounds is " << TroyPounds << endl;
    cout << "Mass in grams is " << grams << endl;
    
    return 0;
}

void Mass::setMassAvoirdupoisPounds(double value)
{
    avoirdupoisPounds = value;
    drams = value / AVOIRDUPOISPOUNDS;
    troyPounds = drams * TROYPOUNDS;
    grams = drams * GRAMS;
}

void Mass::setMassTroyPounds(double value)
{
    troyPounds = value;
    drams = value / TROYPOUNDS;
    grams = drams * GRAMS;
    avoirdupoisPounds = drams * AVOIRDUPOISPOUNDS;

}

void Mass::setMassMetricGrams(double value)
{
    grams = value;
    drams = value * grams;
    troyPounds = drams * TROYPOUNDS;
    avoirdupoisPounds = drams * AVOIRDUPOISPOUNDS;
}

double Mass::getMassAvoirdupoisPounds(void) const
{
    return avoirdupoisPounds;
}

double Mass::getMassTroyPounds(void) const
{
    return troyPounds;
}

double Mass::getMassMetricGrams(void) const
{
    return grams;
}
