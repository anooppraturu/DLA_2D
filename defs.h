#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#ifndef DLA_DEFS_H_
#define DLA_DEFS_H_

#define Real double

/* Step size, box size, and particle size */
#define dt 0.025
#define L 5.0
#define eps 0.1

/* Misc functions */
#define SQR(a) ((a)*(a))
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

typedef struct Particle_s ParticleS;
typedef struct Aggregate_s AggregateS;

struct Particle_s
{
   Real x, y;
   ParticleS *next;
};

struct Aggregate_s
{
   ParticleS *original;
   ParticleS *last;
   int NPTS;
};

#endif /* DLA_DEFS_H_ */
