class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        # Solution 1
        # Loop over one word and check for the length of both words contninuesly 
        merged_string = ''
        word1_len = len(word1)
        word2_len = len(word2)
        for i in range(0, word1_len):
            if i > (word2_len - 1):
                merged_string += word1[i:]
                break
            elif i == (word1_len-1) and i < (word2_len - 1):
                merged_string += word1[i] + word2[i:]
                break
            merged_string += word1[i] + word2[i]

        return merged_string
    

        #  ------------------------
        # Solution 2
        # Use tow pointers
        merged_string = ''
        p1 = 0
        p2 = 0
        word1_len = len(word1)
        word2_len = len(word2)
        while (p1 < word1_len and p2 < word2_len):
            merged_string += word1[p1] + word2[p2]
            p1+=1
            p2+=1

        if p1 < word1_len:
            merged_string += word1[p1:]

        if p2 < word2_len:
            merged_string += word2[p2:]

        return merged_string


        