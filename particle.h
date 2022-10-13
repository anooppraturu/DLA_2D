#include "defs.h"
#include "random.h"

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

/* allocate and initialize a particle */
ParticleS* make_particle(void);

/* step particle forward */
void step(ParticleS *part);

#endif /* _PARTICLE_H_ */
