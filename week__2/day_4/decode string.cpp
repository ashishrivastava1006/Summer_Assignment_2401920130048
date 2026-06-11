class Solution:
    def decodeString(self, s: str) -> str:
        count_stack = []
        string_stack = []

        current_string = ""
        current_number = 0

        for ch in s:
            if ch.isdigit():
                current_number = current_number * 10 + int(ch)
            elif ch == '[':
                count_stack.append(current_number)
                string_stack.append(current_string)
                current_number = 0
                current_string = ""
            elif ch == ']':
                repeat = count_stack.pop()
                prev = string_stack.pop()
                current_string = prev + current_string * repeat
            else:
                current_string += ch

        return current_string
