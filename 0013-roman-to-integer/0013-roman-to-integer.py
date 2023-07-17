class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {"I":1,"V":5,"IV":4, "X":10,"IX":9,"L":50,"XL":40,"C":100, "XC":90,"D":500,"CD":400,"M":1000, "CM":900}
        res = 0
        i = 0
        while i < len(s):
            if s[i:i+2] in roman:
                res += roman[s[i:i+2]]
                i+=2
            else:
                res += roman[s[i]]
                i+=1
        return res