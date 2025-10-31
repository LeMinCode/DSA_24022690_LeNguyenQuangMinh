#include <iostream>
#include "../SymbolTable.h"
using namespace std;

int main() {
    SymbolTable st;

    st.put("E", 5);
    st.put("A", 1);
    st.put("S", 19);
    st.put("Y", 25);
    st.put("Q", 17);

    cout << "Symbol Table (sorted):" << endl;
    st.show();

    cout << "\nMin key: " << st.KeyMin() << endl;
    cout << "Max key: " << st.KeyMax() << endl;
    cout << "Rank of Q: " << st.rank("Q") << endl;
    cout << "Select(2): " << st.select(2) << endl;
    cout << "Floor of R: " << st.floor("R") << endl;
    cout << "Ceiling of R: " << st.ceiling("R") << endl;
}
