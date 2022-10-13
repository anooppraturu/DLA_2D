#include "particle.h"

ParticleS* make_particle(void)
{
   ParticleS *part=NULL;

   /* allocate memory for particle */
   part = (ParticleS*) calloc(1, sizeof(ParticleS));

   /* initialize position in opposite corner from center */
   part->x = L;
   part->y = L;

   return part;
}

void step(ParticleS *part)
{
   Real U1, U2;

   /* Use BM transform to draw step */
   U1 = rand_u(); U2 = rand_u();
   part->x += dt*sqrt(-2.0*log(U1)) * cos(2.0*M_PI*U2);
   part->y += dt*sqrt(-2.0*log(U1)) * sin(2.0*M_PI*U2);
   /* apply boundary conditions */
   if (part->x > L)
      part->x = -1.0*L + fmod(part->x, L);
   else if (part->x < -1.0*L)
      part->x = L + fmod(part->x, L);
   if (part->y > L)
      part->y = -1.0*L + fmod(part->y, L);
   else if (part->y < -1.0*L)
      part->y = L + fmod(part->y, L);

   return;
}
