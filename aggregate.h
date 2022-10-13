#include "defs.h"
#include "particle.h"

#ifndef _AGG_H_
#define _AGG_H_

/* allocate and initialize aggregate */
AggregateS* make_agg(void);
/* find minimum distance from particle to aggregate */
Real dist_to_agg(AggregateS* agg, ParticleS* part);
/* add a particle to the aggregate */
void add_particle(AggregateS* agg);
/* free memory */
void free_aggregate(AggregateS* agg);
/* write aggregate point coordinates to file */
void write_aggregate(AggregateS* agg);

#endif /* _AGG_H_ */
