/* buscar valor en Btree */
void buscarValor(int val, int *pos, btreeNode *miNodo) {
    if (!miNodo) {
        return;
    }
 
    if (val < miNodo->val[1]) {
        *pos = 0;
    }
    else {
        for (*pos = miNodo->count;
            (val < miNodo->val[*pos] && *pos > 1); (*pos)--);
        if (val == miNodo->val[*pos]) {
            cout << "El valor a sido encontrado\n";
            return;
        } else {
        	cout << "El valor no a sido encontrado\n";
		}
    }
    buscarValor(val, pos, miNodo->link[*pos]);
    return;
}