#include <iostream>
#include <string>
//#include <boost/log/trivial.hpp>
using namespace std;


class MyBigNunber
{

    typedef string bignum_str;


    // Gắn độ dài 2 chuỗi cần cộng bằng cách thêm số 0 vào đầu dãy ngắn hơn
    void equal_length(bignum_str& stn1, bignum_str& stn2)
    {
        while (stn1.size() < stn2.size())
            stn1 = '0' + stn1;
        while (stn2.size() < stn1.size())
            stn2 = '0' + stn2;
    }
    //

public: string sum(string stn1, string stn2) {
    equal_length(stn1, stn2);
    int carry = 0;//biến nhớ khi cộng
    bignum_str res;
    for (int i = stn1.size() - 1; i >= 0; i--)
    {
        // Cộng hai chữ số cùng hàng và thêm biến nhớ từ hàng bên phải dồn lên.
        int d = (stn1[i] - '0') + (stn2[i] - '0') + carry;
        carry = d / 10; // Biến nhớ bằng kết quả hàng trước chia 10.
        res = (char)(d % 10 + '0') + res; // Viết chữ số cuối của kết quả.
    }
    if (carry)
        res = '1' + res;

    return res;
}

};
void main() {
    MyBigNunber myclass;
    string stn1 = "1234";
    string stn2 = "789";
    cout<< "Ket Qua Phep Tinh: "<< stn1 <<" + "<< stn2 <<" La: " << myclass.sum(stn1, stn2);
    //BOOST_LOG_TRIVIAL(info) << "Ket Qua Phep Tinh: " << stn1 << " + " << stn2 << " La: " << myclass.sum(stn1, stn2);
}