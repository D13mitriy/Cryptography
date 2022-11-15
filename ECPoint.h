#include <bigInt.h>


class ECPoint {
	bigInt::bigInt_t * x_;
	bigInt::bigInt_t * y_;
	
public:
    //constructors
    ECPoint();
    ECPoint(bigInt::bigInt_t * x, bigInt::bigInt_t * y);
    
    //methods
    
    bool              IsOnCurve(ECPoint a);
    ECPoint         AddECPoints(ECPoint a);
    ECPoint               DoubleECPoints();
    ECPoint ScalarMult(bigInt::bigInt_t n);
    std::string          ECPointToString();
    void                    PrintECPoint();
	
	
};

