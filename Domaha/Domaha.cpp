#include <iostream>
#include "Date.h"

int main()
{
    Date naw;
    Date past(12, 6, 1948);
    naw = past;
    past += naw;
    naw = past - naw;
}

