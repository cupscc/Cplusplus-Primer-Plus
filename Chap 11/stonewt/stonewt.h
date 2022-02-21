#ifndef STONEWT_H
#define STONEWT_H
class Stonewt
{
private:
    const static int Libs_per_stn = 14;
    int stone;
    double pds_left;
    double pounds;

public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    // conversion function
    explicit operator int() const;
    explicit operator double() const;
};
#endif