typedef struct vector* pvector;
 
struct vector
{
    int *data;
    int size, capacity;
};
 
pvector init(int n);
 
pvector insert(pvector v, int x);
 
pvector erase(pvector v, int i);
 
void destruct(pvector v);