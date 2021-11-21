typedef struct raw Raw;

typedef struct processed Processed;

void save_raw(char * fname, Raw * data, int size);

void save_processed(char * fname, Processed data);

void load_raw(char * fname, Raw * data, int size);