import numpy as np

def grad ( p ) :
    # np . poly1d c o n si d e r a p u t e r e maxima pe prima p o z i t i e i n v e c t o r
    p = np . poly1d ( np . flipud ( p ) )
    return p . order


def X(m) :
    # r e p r e z i n t a X^m - - - > [ 0 0 . . . 0 1 ]
    X = np.zeros(m+1, dtype=int )
    X[m] = 1
    return X

class GF2m:
    def __init__ ( self , g ) :
        self.g = g
        self.m = grad ( g )
        self.n = np . power ( 2 , self.m) - 1
        self.k = self.n - self.m
        self.p = self . adunare_polinoame (X(self.n ) , X( 0 ) ) # X^n + 1
        ( self.h , _) = self.divizare_polinoame ( self.p , self.g )
    def adunare_polinoame ( self , a , b ) :
        s = np .mod( np.flipud ( np . polyadd ( np.flipud( a ) , np.flipud ( b ) ) ) , 2 )
        return s.astype ( int )
    def inmultire_polinoame ( self , a , b ) :
        p = np . mod( np.flipud ( np . polymul ( np.flipud ( a ) , np.flipud ( b ) ) ) , 2 )
        # In al g e b r a p oli n o am el o r modulo (X^n + 1 ) , X^n = X^0 , X^(n+1) = X^1 , ...s . a .m. d .
        if grad ( p ) > self.n - 1 :
            for i in range ( self . n , grad ( p ) +1) :
                p [ i - self.n ] = np . mod( p [ i - self.n ] + p [ i ] , 2 )
                p [ i ] = 0
        p = p [ 0 : grad ( p ) +1]
        return p
    def divizare_polinoame ( self , a , b ) :
        ( cat , rest ) = np . polydiv ( np .flipud ( a ) , np.flipud ( b ) )
        cat = np . mod( np . flipud ( cat ) , 2 )
        rest = np . mod( np . flipud ( rest ) , 2 )
        return cat . astype ( int ) , rest . astype ( int )
t = np . array ( [ 1 , 1 , 0 , 1 ] ) # 1+X+X^3
gf2m = GF2m(t)
print ( ' C o e f i c i e n t i i p oli n om ul ui p : ' , gf2m . p )
print ( ' C o e f i c i e n t i i p oli n om ul ui h : ' , gf2m . h )
s = gf2m . adunare_polinoame ( np . array  ( [ 1 , 0 , 1 ] ) , np . array ( [ 1 , 1 ] ) )
print ( 'Suma p oli n o am el o r 1+X^2 s i 1+X e s t e : ' , s )
p = gf2m . inmultire_polinoame ( np . array  ( [ 1 , 0 , 1 , 0 , 0 , 1 ] ) , np .array  ( [ 1 , 0 , 1 , 1 ] ) )
print ( ' I nm ul ti r e a p oli n o am el o r 1+X^2+X^5 s i 1+X^2+X^3 e s t e : ' , p )
( c , r ) = gf2m . divizare_polinoame ( np .array  ( [ 1 , 0 , 1 , 0 , 0 , 1 ] ) , np . array  ( [ 1 , 0 , 1 , 1 ] ) )
print ( ' Im p a r ti r e a p oli n o am el o r 1+X^2+X^5 s i 1+X^2+X^3 e s t e : c a t = ' , c , ' r e s t ...= ' , r )

A='KEEIBNF'
def get_bin(x, n=0):
    return format(x, 'b').zfill(n)

def al7(vec):
    if (len(vec)<7):
        for i in range(7-len(vec)):
            vec.append(0)

    return vec
def al3(vec):
    if (len(vec)<3):
        for i in range(3-len(vec)):
            vec.append(0)

    return vec
def g1_encode(text: str) -> np.ndarray :

    a=[]
    for p in text:
        pp = list(map(int, get_bin(ord(p) - 65, 4)))
        # print (pp)
        z = gf2m.inmultire_polinoame(np . array  ( [ 0 , 0 , 0 , 1] ),pp)
        (c, r) = gf2m.divizare_polinoame(z,np . array  ( [ 1 , 0 , 1 , 1 ] ))
        # print (r," ",z)
        v=gf2m.adunare_polinoame(r,z)
        v=al7(list(v))
        # v[0:3]=np.flipud(v[0:3])
        # v[3:7] = np.flipud(v[3:7])
        a.append(list(v))


    return a
A='ABCP'
f=g1_encode(A)
# print (f)
def bin1dec ( a ) :
    b = 0
    for p in range ( len ( a ) ) :
        b+=a[-p-1]*(2**p)
    return np.int32(b)
def bin2dec ( a ) :
    b = 0

    H = np.array([[0 ,0 ,1 ,0 ,1 ,1 ,1],
       [0 ,1 ,0 ,1 ,1 ,1 ,0],
       [1 ,0 ,1 ,1 ,1 ,0 ,0]])
    for p in range ( len ( H[0] ) ) :
        if (np.array_equal(a ,H[:,p])):

            b=p
            break
    # print (b)
    return b
def g1_decode(code_matrix: np.ndarray) -> str :
    H=[[0 ,0 ,1 ,0 ,1 ,1 ,1],
       [0 ,1 ,0 ,1 ,1 ,1 ,0],
       [1 ,0 ,1 ,1 ,1 ,0 ,0]]

    a=[]
    ss=str()
    for p in code_matrix:
        # p=np.flipud(p)
        # p[0:3] = np.flipud(p[0:3])
        # p[3:7] = np.flipud(p[3:7])
        (c, r) = gf2m.divizare_polinoame(p, np.array([1, 0, 1, 1]))
        r=al3(list(r))
        # print(r)
        a.append(list(r))
        # print(np.all(list(r)==[0,0,0]))
        if (~np.all(list(r)==[0,0,0])):

            n=int(bin2dec(np.flipud(r)))
            # print(np.flipud(r))
            # print(n+1)
            p=gf2m.adunare_polinoame(p,X(n))

            s = p[3:7]
            # print(chr(bin1dec(s)+65))
            ss=ss+(chr(bin1dec(s)+65))

        else:
            s = p[3:7]
            # print(chr(bin1dec(s) + 65))
            ss = ss + (chr(bin1dec(s) + 65))






    return ss
