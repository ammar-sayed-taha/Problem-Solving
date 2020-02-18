

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score > b.score)
            return 0; // no sort
        else if(a.score < b.score)
            return -1; // sort
        else {
            // sort by name ASC
            int comp = a.name.compare(b.name);
            if(comp > 0) // a.name > b.name
                return -1; // sort
            else if(comp < 0) // a.name < b.name
                return 0; //  no sort
            else  // a.name = b.name
                return 0;

        }
    }
};

