# mbm
quickly navigate between directories in the terminal.
again, quick and dirty program that **just works for me**.  

## example
`mbm <file>`

keys can only be a single character because that's all i need.
the config <file> should be full of key:value pairs like this:
```
a:/home/urmom/
b:/home/urmom/bruh/
```

to cd into selected directory:
```bash
mbm() {
    command mbm $1
    DIR=$(cat ~/.mbmsel)
    if [ $DIR != "NULL" ]; then
        cd $DIR
    fi
}
```
