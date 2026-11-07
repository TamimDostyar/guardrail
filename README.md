This will work as a sandbox but not with virtualization or any sort of isolation.
    - This is simply restricting the software to stay within the system


To build the guardrail:
    - `gcc -Wall -Wextra -I src/header  main.c     src/core/configuration/configuration.c     src/core/files/files.c     src/core/isolation/isolate.c     src/core/shell/commandSys.c     -o output/guardrail`

    - `./output/guardrail guard --start-connection`
    