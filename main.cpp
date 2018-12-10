

#include "matrix.h"
#include "kuhn.h"

int main()
{
    Matrix S(2,2);
    S.set(1,1,1);
    S.set(1,2,2);
    S.set(2,1,3);
    S.set(2,2,4);
    S.display();
    Matrix D=increase_dim(S);
    D.display();
    return 0;
}
