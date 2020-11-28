#include <stdio.h>
#include "queue.h"
#include "stackt.h"
#include "wahanatree.c"
#include "filewahana.c"
#include "jam.h"
#include "jam.c"
#include "boolean.h"
#include "point.h"


//

void detail(POINT posisi){
    //posisi player dimana?
    //disebelahnya ada wahana
    if(checkSekitar(&Map, posisi)){

    }//lah ngecek disampingnya ada wahana apanya juga gimana wkwkwk
    //baca data wahana itu
     //cara baca datanya gimana cuy wkwkwk
}

void prepare(Queue Q, Jam *JamDunia)
{
    //Mengosongkan anrian pengunjung dan langsung memulai ​preparation phase​
    DelQueueAll(Q); //ini fungsi buat ngebuang isi Q kan? Qnya masukin antrian pengunjung
    Hour(*JamDunia) = 15;
}