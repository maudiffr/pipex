# pipex
<br>
<p align="center">
    <img src=https://upload.wikimedia.org/wikipedia/commons/1/19/C_Logo.png alt="Logo C" width="125">
</p>

### Skills

- Process management (`fork`, `execve`, `waitpid`)
- File descriptor handling (`open`, `close`, `dup2`)
- Inter-process communication (`pipe`)
- Error handling and exit codes
- String manipulation and parsing command-line arguments
- Dynamic memory management (`malloc`, `free`)

<br>

## About

`pipex` is a program that mimics shell pipe behavior. It executes two commands separated by a pipe, redirecting input and output files.

Example shell command:
```bash
< infile cmd | cmd2 > outfile
```

is equivalent to running `pipex` as:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

This program has to:

- Take **exactly 4 arguments**: input file, first command, second command, output file.
- Execute the first command and send its output to the second command via a pipe.
- Redirect the standard input and output of commands to the provided files.

<br>

## Usage

**1. Clone the repository**
```bash
git clone git@github.com:maudiffr/pipex.git
cd pipex
```

**2. Compile the project using `make`**
```bash
make
```

**3. Create a simple input file**
```bash
echo -e "Hello\nfoo\nworld" > infile
```

**4. Run the program**
```bash
./pipex infile "grep foo" "wc -l" outfile
cat outfile
```

or
```bash
./pipex infile "ls -l" "wc -l" outfile
cat outfile
```
