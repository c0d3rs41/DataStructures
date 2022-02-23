# DataStructures
This repo contains code implementation of various data structures using c language.<br>
A typical structure definition looks like:
``` 
struct avl
{
	int data;
	struct avl *left, *right;
	int h;
};
```
<br>
All the structure related information and function definitions are kept in adt.h
<br>
Implementation related details are kept in impl.h
<br>
appl.c contains code for a simple application which utilises the data structure.
