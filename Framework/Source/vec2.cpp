#include "CoreHeaders.h"
#include "vec2.h"


namespace fw {

void vec2::test()
{
    vec2 a(5, 10);
    assert(a.X == 5 && a.Y == 10);

    //a.Add(20, 30);
    //assert(a.X == 25 && a.Y == 40);

   // a.Set(5, 10);

    vec2 b(2, 3);
    a += b;
    assert(a.X == 7 && a.Y == 13);

    const vec2 x(1, 1);

    vec2 velocity(10, 10);
    vec2 backwards = -velocity;

    int bp = 1;


    float test = 1;
    test *= 10;
    test *= 10;
    test *= 10;
    test *= 10;

}

}

