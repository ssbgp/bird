//
// Created by david on 10/5/17.
//

#include <malloc.h>

#include "nest/bird.h"
#include "prefix_set.h"


typedef struct prefix_node {
  struct prefix prefix;
  struct prefix_node* next;
} prefix_node;


typedef struct prefix_set {
  prefix_node* front;
} prefix_set;


/**
 * Tests if two prefixes are equal.
 *
 * @param p1 first prefix
 * @param p2 second prefix
 * @return true if the specified prefixes are equal or false, if otherwise
 */
static inline int prefix_are_equal(const struct prefix* p1, const struct prefix* p2)
{
  return p1->len == p2->len && p1->addr == p2->addr;
}

//
// Constructors and destructors
//

/**
 * Creates a new empty set of prefixes.
 *
 * @return a pointer to the newly created set
 */
prefix_set* prefix_set_new(void)
{
  prefix_set* set = malloc(sizeof(prefix_set));

  if (set)
  {
    set->front = NULL;
  }

  return set;
}

/**
 * Deletes the entire list, including its contents.
 *
 * @param set pointer to set to be deleted
 */
void prefix_set_delete(prefix_set* set)
{
  // Free each prefix in the list
  prefix_node* current = set->front;
  while (current)
  {
    prefix_node* prefix_to_delete = current;
    current = current->next;
    free(prefix_to_delete);
  }

  // Free the set structure
  free(set);
}

//
// Modifiers and accessors
//

/**
 * Adds a new prefix to the specified set.
 *
 * @param set    pointer to set to add prefix to
 * @param prefix prefix to add to set
 */
void prefix_set_add(prefix_set* set, const struct prefix* prefix)
{
  if (!prefix_set_contains(set, prefix))
  {
    // Create a new prefix node storing a copy of the specified prefix
    prefix_node* new_prefix = malloc(sizeof(prefix_node));
    new_prefix->prefix = *prefix;

    // Insert the new prefix at the front of the "list"
    new_prefix->next = set->front;
    set->front = new_prefix;
  }
}

/**
 * Checks if the specified prefix is already included in the specified set.
 *
 * @param set    pointer to set that may contain the prefix
 * @param prefix prefix to look for in the specified set
 * @return 1 if the specified prefix is included in the set or 0, if otherwise.
 */
int prefix_set_contains(const prefix_set* set, const struct prefix* prefix)
{
  prefix_node* current = set->front;
  while (current)
  {
    if (prefix_are_equal(&current->prefix, prefix))
      return 1;

    current = current->next;
  }

  return 0;
}
