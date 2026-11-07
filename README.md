# Guardrail

Guardrail currently provides a command dispatcher and restricts its working
directory to `/tmp/guardrails`. It is not a virtualized or fully isolated
sandbox.

## Build

From the repository root:

```bash
mkdir -p output
gcc -Wall -Wextra -I src/header \
    main.c \
    src/core/configuration/configuration.c \
    src/core/files/files.c \
    src/core/isolation/isolate.c \
    src/core/shell/commandSys.c \
    -o output/guardrail
```

## Run

```bash
./output/guardrail guard --start-connection
```

Available commands:

```text
guard --start-connection
guard --stop-connection
guard --start-command
guard --stop-command
guard --start-limitation
guard --stop-limitation
```
