//
// Created by david on 10/5/17.
//

#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

struct prefix;

typedef struct prefix_node prefix_node;
typedef struct prefix_set prefix_set;

prefix_set* prefix_set_new(void);
void prefix_set_delete(prefix_set *set);

void prefix_set_add(prefix_set *set, const struct prefix *prefix);
int prefix_set_contains(const prefix_set *set, const struct prefix *prefix);

#endif //DATA_STRUCTURES_LIST_H
