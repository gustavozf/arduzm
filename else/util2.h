//#define F_CPU 16000000UL // UL == Unsigned Long

// bit operations
#define swt_bit(x,n) (x ^= (1<<n))
#define add_bit(x,n) (x |= (1<<n))
#define rem_bit(x,n) (x &= ~(1<<n))
#define comp_masks(x, y) ((1<<x)|(1<<y))
#define check_pin(x, y) (x & (1 << y))
