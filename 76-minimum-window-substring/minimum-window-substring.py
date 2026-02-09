class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        # Dictionary which keeps a count of all the unique charactes in t.
        dict_t = Counter(t)

        # Number of unique charactes in t, which need to be present in the desired window
        required = len(dict_t)

        # left and right pointer
        l, r = 0, 0

        # Formed is used to keep track of how many unique characters in t are present in current window in its desired frequency.
        # e.g. if it is "AABC" then the window muct have two 'A's, one B and one C. Thus formed would be = 3 when all these conditions are met.
        formed =0

        # Dictionary which keeps a count of all the unique characters in the current window
        window_counts = {}

        # and tuple of the form (window, length, left, right)
        ans = float("inf"), None, None

        while r < len(s):
            character = s[r]
            window_counts[character] = window_counts.get(character, 0) + 1

            # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1
            if(character in dict_t and window_counts[character] == dict_t[character]):
                formed += 1

            # Try and contract the window till the point where it ceases to be 'desirable'.
            while l <= r and formed == required:
                character = s[l]

                # Save the smallest window until now
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)

                # The Character at the position by the 'left' pointer is no longer a partof the window.
                window_counts[character] -= 1
                if (character in dict_t and window_counts[character] < dict_t[character]):
                    formed -= 1

                # Move the left pointer ahead, this would help to look for a new window.
                l += 1

            # Keep expanding the window once we are done contracting.
            r += 1

        return "" if ans[0] == float("inf") else s[ans[1]:ans[2]+1]
        
