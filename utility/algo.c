/***********************************************************************
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#include <stdlib.h>
#include <string.h>
#include <math.h> /* pow, sqrt, exp */
#include <time.h>
#include "algo.h"

void quick_sort(float* h, int left, int right)
{
    if(h==NULL) return;
    if(left>=right) return;

    srand((unsigned)time(NULL));
    int len=right-left;
    int kindex=rand()%(len+1)+left;
    float tmp = h[left];
    h[left] = h[kindex];
    h[kindex] = tmp;

    float key=h[left];
    int i=left,j=right;
    while(i<j)
    {
        while(h[j]<key && i<j) --j;
        if(i<j) h[i]=h[j];
        while(h[i]>=key && i<j) ++i;
        if(i<j) h[j]=h[i];
    }

    h[i]=key;

    quick_sort(h,left,i-1);
    quick_sort(h,j+1,right);
}
