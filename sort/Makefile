.PHONY: all

BINS = merge_sort_array merge_sort_list quick_sort
OBJS = $(wildcard *.o)

all: $(BINS)

merge_sort_array: merge_sort_array.o
	gcc -o $@ $<
merge_sort_array.o: merge_sort_array.c
	gcc -o $@ -c $<

merge_sort_list: merge_sort_list.o
	gcc -o $@ $<
merge_sort_list.o: merge_sort_list.c
	gcc -o $@ -c $<

quick_sort: quick_sort.o
	g++ -o $@ $<
quick_sort.o: quick_sort.cpp
	g++ -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(BINS) $(OBJS) 
