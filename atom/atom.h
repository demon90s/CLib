#ifndef ATOM_H
#define ATOM_H

/*
    atom is an unique character sequence
    if two atom's address is equal, then they are equal
    atom can be used as key
*/

/*
    find the atom by it's address, return it's length
    if str is not an atom, it will raise a runtime error
*/
extern int Atom_length(const char* str);

/* find or make a new atom */
extern const char* Atom_new(const char* str, int len);

/* find or make a new atom by c-style string */
extern const char* Atom_string(const char* str);

/* n will be translated to a string, and find or make the atom */
extern const char* Atom_int(long n);

/*
    the atom pool is global object
    It is not necessary to call this function, but it does not matter
*/
extern void Atom_destroy();

#endif
