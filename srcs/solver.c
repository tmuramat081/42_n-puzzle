#include "ft_priqueue.h"
#include "ft_hashset.h"

void a_tar_search(t_node *first_node, const t_solver *solver)
{
  t_priority_queue *open;
  t_hashmap *closed;

  open = ft_priority_queue_init(10, priority_comparator);
  closed = ft_hashset_init(hash_node, hash_node_free);
  
  return;
}

