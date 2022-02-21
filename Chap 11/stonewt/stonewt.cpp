#include <iostream>
#include "stonewt.h"
using std ::cin;
using std ::cout;
Stonewt::Stonewt(double libs)
{
    stone = int(libs) / Libs_per_stn;
    pds_left = int(libs) % Libs_per_stn + libs - int(libs);
    pounds = libs;
}
Stonewt::Stonewt(int stn, double libs)
{
    stone = stn;
    pds_left = libs;
    pounds = stn * Libs_per_stn + libs;
}
Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}
Stonewt ::~Stonewt()
{
}
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << "pounds\n";
}
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds";
}
Stonewt ::operator int() const
{
    return int(pounds + 0.5);
}
Stonewt ::operator double() const // conversion function
{
    return double(pounds);
}
void display(const Stonewt &st)
{
    cout << "wow";
    st.show_stn();
}
int main()
{
    Stonewt myCat;
    myCat = 19.6;
    // Stonewt myDog = 100;
    // myCat.show_stn();
    // myDog.show_stn();
    // display(41.6);
    double pig = myCat;
    cout << pig;
    return 0;
}