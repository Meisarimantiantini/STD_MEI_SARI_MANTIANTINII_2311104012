#include <iostream>
#include "list.h"
using namespace std;

void createList (List &L){
    first (L) = NULL;
}

address allocate(infotype x){
    address p = new elmList;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertFirst(List &L, address P){
    P->next = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
         } else {
        address last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        last->next = P;
        }
}

void insertAfter(List &L, address P, infotype x) {
    address current = first(L);
    while (current != NULL && info(current) != x) {
        current = next(current);
    }
    if (current != NULL) { // Jika elemen ditemukan
        P->next = current->next;
        current->next = P;
    }
}

void deleteLast(List &L) {
    if (first(L) == NULL) {
        cout << "List kosong, tidak ada elemen untuk dihapus." << endl;
        return;
    
    }
  
    if (next(first(L)) == NULL) { 
        delete first(L);
        first(L) = NULL;
    } else {
        address current = first(L);
        while (next(next(current)) != NULL) { 
            current = next(current);
        }
        delete next(current); 
        current->next = NULL; 
    }
}

// Prosedur untuk menghapus elemen setelah elemen tertentu
void deleteAfter(List &L, infotype x) {
    address current = first(L);
    while (current != NULL && info(current) != x) {
        current = next(current);
    }
    if (current != NULL && next(current) != NULL) { 
        address temp = next(current);
        current->next = next(temp); 
        delete temp; 
    }
}

// Fungsi untuk mencari elemen dalam list
address searchInfo(List L, infotype x) {
    address current = first(L);
    while (current != NULL) {
        if (info(current) == x) {
            return current; 
        }
        current = next(current);
    }
    return NULL; 
}


void printInfo(List L){
    address p = first(L);
    while (p != NULL){
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}