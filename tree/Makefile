all: binary_search_tree avl_tree

binary_search_tree: binary_search_tree.c
	gcc -o binary_search_tree binary_search_tree.c

avl_tree: avl_tree.c
	gcc -o $@ $<

trie: trie.c
	gcc -o $@ $<
	
.PHONY:clean
clean:
	rm -f *.o $(all)