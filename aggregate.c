#include "aggregate.h"

AggregateS* make_agg(void)
{
   AggregateS *agg = NULL;

   /* allocate memory for aggregate */
   agg = (AggregateS*) calloc(1, sizeof(AggregateS));

   /* Initialize center*/
   agg->original = make_particle();
   agg->original->x = agg->original->y = 0.0;
   agg->original->next = agg->original;

   /* Initialize last point */
   agg->last = agg->original;

   agg->NPTS = 1;

   return agg;
}

Real dist_to_agg(AggregateS* agg, ParticleS* part)
{
   int n;
   Real min;
   ParticleS *tmp = agg->original;

   /* loop over points in aggregate and find minimum distance from new point */
   min = SQR(tmp->x - part->x) + SQR(tmp->y - part->y);
   if (1 == agg->NPTS){
      return sqrt(min);
   }
   else{
      for(n=0; n<agg->NPTS-1; n++){
         tmp = tmp->next;
         min = MIN(min, SQR(tmp->x - part->x) + SQR(tmp->y - part->y));
      }
   }

   return sqrt(min);
}

void free_aggregate(AggregateS* agg)
{
   int n;
   ParticleS *tmp1 = agg->original, *tmp2 = NULL;

   /* loop over points in agg and free each one */
   for (n=0; n<agg->NPTS; n++){
      tmp2 = tmp1->next;
      free(tmp1);
      tmp1 = tmp2;
   }

   /* free pointer to aggregate */
   free(agg);

   return;
}

void add_particle(AggregateS* agg)
{
   Real dist;
   ParticleS *new = NULL;

   /* allocate and initialize new particle */
   new = make_particle();
   dist = dist_to_agg(agg, new);

   /* walk until hits aggregate */
   while (dist > eps){
      step(new);
      dist = dist_to_agg(agg, new);
   }

   /* insert particle into aggregate */
//   new->next = agg->original->next;
//   agg->original->next = new;
   agg->last->next = new;
   new->next = agg->original;
   agg->last = new;

   /* increment particle count */
   agg->NPTS += 1;

   return;
}

/* write particle coordinates to file in the order that they aggregate */
void write_aggregate(AggregateS* agg)
{
   int n;
   FILE *fp;
   ParticleS *tmp=NULL;

   fp = fopen("cluster_pts.dat", "w");

   /* print file header */
   fprintf(fp, "NPTS=%d, \t dt=%f, \t L=%f, \t eps=%f\n", agg->NPTS, dt, L, eps);

   tmp = agg->original;
   for (n=0; n<agg->NPTS; n++){
      fprintf(fp, "%d\t%f\t%f\n", n+1, tmp->x, tmp->y);
      tmp = tmp->next;
   }

   fclose(fp);
   return;
}





