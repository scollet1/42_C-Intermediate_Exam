#ifdef TESTING
#include <stdio.h>
#endif

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue	*init(void) {
	struct s_queue *q;

	if (!(q = (struct s_queue*)malloc(sizeof(struct s_queue)))) return (NULL);
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void			enqueue(struct s_queue *queue, void *content) {
	struct s_node *new;

	if (!queue) return;
	if (!(new = (struct s_node*)malloc(sizeof(struct s_node)))) return;
	new->content = content;
	if (!queue->first) {
		queue->first = queue->last = new;
		new->next = NULL;
	} else {
		queue->last->next = new;
	}
}

void			*dequeue(struct s_queue *queue) {
	struct s_node	*first;
	void			*data;

	if (!queue) return (NULL);
	if (!queue->first || !queue->last) return (NULL);
	first = queue->first;
	queue->first = queue->first->next;
	data = first->content;
	free(first);
	first = NULL;
	return (data);
}

void			*peek(struct s_queue *queue) {
	if (!queue) return (NULL);
	return (queue->first->content);
}

int				isEmpty(struct s_queue *queue) {
	if (!queue) return (1);
	return (queue->first? 0:1);
}

#ifdef TESTING
int	main(void) {
	struct s_queue *q = NULL;

	enqueue(q, "sup");
	printf("deq %s\n", (char*)dequeue(q));
	q = init();

	printf("deq %s\n", (char*)dequeue(q));
	printf("lol\n");
	printf("emt %d\n", isEmpty(q));
	enqueue(q, "sup");
	printf("deq %s\n", (char*)dequeue(q));
	printf("deq %s\n", (char*)dequeue(q));
	printf("deq %s\n", (char*)dequeue(q));
	enqueue(q, "1");
	printf("deq %s\n", (char*)dequeue(q));
	enqueue(q, "2");
	printf("emt %d\n", isEmpty(q));
	printf("pik %s\n", (char*)peek(q));
	printf("deq %s\n", (char*)dequeue(q));
	printf("emt %d\n", isEmpty(q));
	enqueue(q, "3");
	printf("deq %s\n", (char*)dequeue(q));
	enqueue(q, "for");
	printf("emt %d\n", isEmpty(q));
	printf("deq %s\n", (char*)dequeue(q));
	enqueue(q, "5ive");
	printf("deq %s\n", (char*)dequeue(q));
	return (0);
}
#endif
