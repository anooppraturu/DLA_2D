#include "defs.h"
#include "aggregate.h"

int main(void)
{
   AggregateS *agg = NULL;
   int n;
   ParticleS *tmp;
   
   /* Set random seed */
   srand(time(0));
   
   /* allocate and initialize aggregate */
   agg = make_agg();
   /* grow aggregate by diffusion */
   for (n=0; n<500; n++){
      add_particle(agg);
   }
   /* write data to file */
   write_aggregate(agg);
   /* free memory */
   free_aggregate(agg);

   return 0;
}
