//#define F_CPU 16000000UL // UL == Unsigned Long

// bit operations
#define swtBit(x,n) (x ^= (1<<n))
#define addBit(x,n) (x |= (1<<n))
#define remBit(x,n) (x &= ~(1<<n))
#define compMasks(x, y) ((1<<x)|(1<<y))
#define checkPin(x, y) (x & (1 << y))
