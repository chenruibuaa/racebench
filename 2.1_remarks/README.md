# racebench 2.1_remarks

该测试集仅适用于单变量访问序模式的测试。

该测试集为简单测试集racebench2.1带注释版本，给出了预埋的bug点和预埋的误报点。

*注：*

* *所有用例均遵循标准C语法。*
* *测试用例不考虑中断的周期性，中断可以在允许中断的情况下打断主程序或者低级中断，打断的时刻不定，位置不定，次数不定。*

## 用例集配置说明

* 中断号用于测试用例中提供的中断开关函数。enable_isr(n)和disable_isr(n)可视为unlock和lock原语。其中n表示中断号，当n为-1时，表示屏蔽/打开所有中断。
* 优先级数字越大，优先级越高

### 简单用例集

共31个测试用例。

| 序号 | 用例名               | 主程序入口              | 中断入口/中断号/优先级                                       |
| ---- | -------------------- | ----------------------- | ------------------------------------------------------------ |
| 1    | svp_simple_001_001.c | svp_simple_001_001_main | svp_simple_001_001_isr_1/1/1   svp_simple_001_001_isr_2/2/2  |
| 2    | svp_simple_002_001.c | svp_simple_002_001_main | svp_simple_002_001_isr_1/1/1     svp_simple_002_001_isr_2/2/2 |
| 3    | svp_simple_003_001.c | svp_simple_003_001_main | svp_simple_003_001_isr_1/1/1     svp_simple_003_001_isr_2/2/2 |
| 4    | svp_simple_004_001.c | svp_simple_004_001_main | svp_simple_004_001_isr_1/1/1    svp_simple_004_001_isr_2/2/2 |
| 5    | svp_simple_005_001.c | svp_simple_005_001_main | svp_simple_005_001_isr_1/1/1                                 |
| 6    | svp_simple_006_001.c | svp_simple_006_001_main | svp_simple_006_001_isr_1/1/1                                 |
| 7    | svp_simple_007_001.c | svp_simple_007_001_main | svp_simple_007_001_isr_1/1/1                                 |
| 8    | svp_simple_008_001.c | svp_simple_008_001_main | svp_simple_008_001_isr_1/1/1                                 |
| 9    | svp_simple_009_001.c | svp_simple_009_001_main | svp_simple_009_001_isr_1/1/1                                 |
| 10   | svp_simple_010_001.c | svp_simple_010_001_main | svp_simple_010_001_isr_1/1/1                                 |
| 11   | svp_simple_011_001.c | svp_simple_011_001_main | svp_simple_011_001_isr_1/1/1                                 |
| 12   | svp_simple_012_001.c | svp_simple_012_001_main | svp_simple_012_001_isr_1/1/1                                 |
| 13   | svp_simple_013_001.c | svp_simple_013_001_main | svp_simple_013_001_isr_1/1/1  svp_simple_013_001_isr_2/2/2  svp_simple_013_001_isr_3/3/3 |
| 14   | svp_simple_014_001.c | svp_simple_014_001_main | svp_simple_014_001_isr_1/1/1    svp_simple_014_001_isr_2/2/2   svp_simple_014_001_isr_3/3/3 |
| 15   | svp_simple_015_001.c | svp_simple_015_001_main | svp_simple_015_001_isr_1/1/1                                 |
| 16   | svp_simple_016_001.c | svp_simple_016_001_main | svp_simple_016_001_isr_1/1/1                                 |
| 17   | svp_simple_017_001.c | svp_simple_017_001_main | svp_simple_017_001_isr_1/1/1                                 |
| 18   | svp_simple_018_001.c | svp_simple_018_001_main | svp_simple_018_001_isr_1/1/1  svp_simple_018_001_isr_2/2/2   |
| 19   | svp_simple_019_001.c | svp_simple_019_001_main | svp_simple_019_001_isr_1/1/1                                 |
| 20   | svp_simple_020_001.c | svp_simple_020_001_main | svp_simple_020_001_isr_1/1/1   svp_simple_020_001_isr_2/2/2  |
| 21   | svp_simple_021_001.c | svp_simple_021_001_main | svp_simple_021_001_isr_1/1/1                                 |
| 22   | svp_simple_022_001.c | svp_simple_022_001_main | svp_simple_022_001_isr_1/1/1                                 |
| 23   | svp_simple_023_001.c | svp_simple_023_001_main | svp_simple_023_001_isr_1/1/1                                 |
| 24   | svp_simple_024_001.c | svp_simple_024_001_main | svp_simple_024_001_isr_1/1/1                                 |
| 25   | svp_simple_025_001.c | svp_simple_025_001_main | svp_simple_025_001_isr_1/1/1                                 |
| 26   | svp_simple_026_001.c | svp_simple_026_001_main | svp_simple_026_001_isr_1/1/1     svp_simple_026_001_isr_2/2/2 |
| 27   | svp_simple_027_001.c | svp_simple_027_001_main | svp_simple_027_001_isr_1/1/1    svp_simple_027_001_isr_2/2/2    svp_simple_027_001_isr_3/3/3 |
| 28   | svp_simple_028_001.c | svp_simple_028_001_main | svp_simple_028_001_isr_1/1/1     svp_simple_028_001_isr_2/2/2    svp_simple_028_001_isr_3/3/3 |
| 29   | svp_simple_029_001.c | svp_simple_029_001_main | svp_simple_029_001_isr_1/1/1                                 |
| 30   | svp_simple_030_001.c | svp_simple_030_001_main | svp_simple_030_001_isr_1/1/1     svp_simple_030_001_isr_2/2/2  svp_simple_030_001_isr_3/3/3 |
| 31   | svp_simple_031_001.c | svp_simple_031_001_main | svp_simple_031_001_isr_1/1/1                                 |

