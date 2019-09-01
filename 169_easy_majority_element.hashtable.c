// using uthash as hashtable implementation
struct hash_entry {
    int id;
    int count;
    UT_hash_handle hh;
};
struct hash_entry *users = NULL;

struct hash_entry *add_user(int user_id) {
    struct hash_entry *s;
    s = (struct hash_entry *) malloc(sizeof(struct hash_entry));
    s->id = user_id;
    s->count = 0;
    HASH_ADD_INT(users, id, s);
    return s;
}
    
struct hash_entry *find_user(int user_id) {
    struct hash_entry *s;
    HASH_FIND_INT(users, &user_id, s);
    return s;
}

void delete_all() {
  struct hash_entry *current_user, *tmp;

  HASH_ITER(hh, users, current_user, tmp) {
    HASH_DEL(users,current_user);  /* delete; users advances to next */
    free(current_user);            /* optional- if you want to free  */
  }
}

// using hashtable
int majorityElement(int* nums, int numsSize){
    int i;
    struct hash_entry *hash_entry;

    for(i = 0; i < numsSize; i++) {
        hash_entry = find_user(nums[i]);
        if(!hash_entry)
            hash_entry = add_user(nums[i]);
        hash_entry->count++;
    }
    
    for(hash_entry = users; hash_entry; hash_entry = hash_entry->hh.next)
        if(hash_entry->count > numsSize/2) {
            i = hash_entry->id;
            delete_all();
            return i;
        }
    
    // doesn't seem to run without this line
    return 0;
    
}
