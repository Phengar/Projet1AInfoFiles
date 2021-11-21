typedef struct raw Raw; // Raw is an alias to struct raw

typedef struct processed Processed; // Processed is an alias to struct processed

void save_raw(char * fname, Raw * data, int size);

void save_processed(char * fname, Processed data);

void load_raw(char * fname, Raw * data, int size);