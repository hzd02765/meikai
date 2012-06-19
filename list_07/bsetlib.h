typedef unsigned long Bset;

#define BsetNull (Bset)0
#define BsetOne (Bset)1
#define BsetBIT 32

#define Bsetof(no) (BsetOne << (no))
