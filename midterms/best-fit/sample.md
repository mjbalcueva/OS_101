```c
|---------------------------------------------------------------------------------
| FIRST FIT
|---------------------------------------------------------------------------------
| BS - 100, 500, 200, 300, 600
| FS - 212, 417, 112, 426
|---------------------------------------------------------------------------------
|        | 100
| F1, F3 | 500 - (212) = 288 - (112) = 176
|        | 200
|        | 300
| F2     | 600 - 417 = 183
|---------------------------------------------------------------------------------
|        | 100
| F4     | NOT ALLOCATED
|---------------------------------------------------------------------------------
| File IDs    File Size   Block IDs  Block Size  |  Transferred FS    Remaining BS
| 1           212         2          500         |  212               288
| 2           417         5          600         |  417               183
| 3           112         2          288         |  112               176
| 4           426         NA         NA          |  NA                NA
|---------------------------------------------------------------------------------



|---------------------------------------------------------------------------------
| BEST FIT
|---------------------------------------------------------------------------------
| BS - 100, 500, 200, 300, 600
| FS - 212, 417, 112, 426
|---------------------------------------------------------------------------------
|        | 100
| F2     | 500 - 417 = 83
| F3     | 200 - 112 = 88
| F1     | 300 - 212 = 88
| F4     | 600 - 426 = 174
|---------------------------------------------------------------------------------
|        | 100
| F4     | NOT ALLOCATED
|---------------------------------------------------------------------------------
| File IDs    File Size   Block IDs  Block Size  |  Transferred FS    Remaining BS
| 1           212         4          300         |  212               88
| 2           417         2          500         |  417               83
| 3           112         3          200         |  112               88
| 4           426         5          600         |  426               174
|---------------------------------------------------------------------------------
```
