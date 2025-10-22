#include "libft.h"
#include<stdio.h>

void    print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main()
{
    t_list    *node1 = ft_lstnew(ft_strdup("first"));
    t_list    *node2 = ft_lstnew(ft_strdup("secoond"));
    t_list    *node3 = ft_lstnew(ft_strdup("third"));

    node1->next = node2;
    node2->next = node3;

    t_list *head = node1;
    
    printf("Testing ft_lstiter:\n");
    ft_lstiter(head, print_content);

    ft_lstclear(&head, free);

	return(0);
}