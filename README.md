# 🔍 Regex-Based Text Analyzer (C++)

## 📌 Project Overview
This project is a **C++ text analysis tool** that uses the Standard Library **`<regex>`** to detect and analyze **case-insensitive variations** of the keyword:

```
fail, fails, failed, failing, failure, failures
```

The program reads input from a text file and produces detailed statistics, then updates the file by transforming matched keywords.

---

## ✨ Features
- Analyze keyword occurrences in a **specific line**
- Count **total occurrences** in the entire file
- Detect line(s) with the **maximum number of matches**
- Identify lines where the keyword appears as the **first word**
- Replace all keyword variations with their **uppercase form**
- Fully **case-insensitive matching**

---

## 📂 Project Structure
```
project/
│── main.cpp        # C++ source code
│── input.txt       # Input text file
│── README.md       # Documentation
```

---

## 🛠 Technologies Used
- **C++17**
- `<regex>` for pattern matching
- `<fstream>` for file handling
- Standard string manipulation

---

## ▶️ How to Compile and Run

### Compile
```bash
g++ main.cpp -o regex_analyzer
```

### Run
```bash
./regex_analyzer
```

---

## 🧪 How It Works
1. The program reads `input.txt` line by line.
2. The user is prompted to enter a line number.
3. Regex patterns detect all variations of the keyword `fail`.
4. Statistics are printed to the console.
5. The file is updated by converting matched keywords to **uppercase**.

---

## 📤 Sample Output
```
Enter line number: 3
Occurrences in line 3: 2
Total occurrences in file: 15
Line(s) with maximum occurrences: 4, 7
Lines where keyword appears first: 2, 6
File updated successfully.
```

---

## ⚠️ Important Notes
- The program works with **any input file**, not only the sample.
- Leading whitespace is ignored when checking the first word.
- The input file is **permanently modified** after execution.

---

## 👨‍💻 Author
**Ahmad Irshaid**
**Software Engineering Student At NNU**

---
## 📘 Course Information
- **Course:** Theory of Computation  
- **Semester:** Fall 2025–2026  
- **Language:** C++  
- **Topic:** Regular Expressions
- **Instructor:** Hamed Abdelhaq
