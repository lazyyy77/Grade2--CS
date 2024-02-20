<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="clkd(31:0)" />
        <signal name="clkd(18:17)" />
        <signal name="XLXN_8(1:0)" />
        <signal name="HEXS(15:0)" />
        <signal name="LES(3:0)" />
        <signal name="points(3:0)" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="AN(3:0)" />
        <signal name="HEX(3:0)" />
        <signal name="Segment(7:0)" />
        <signal name="HEX(3)" />
        <signal name="HEX(2)" />
        <signal name="HEX(1)" />
        <signal name="HEX(0)" />
        <signal name="Segment(7)" />
        <signal name="Segment(6)" />
        <signal name="Segment(5)" />
        <signal name="Segment(4)" />
        <signal name="Segment(3)" />
        <signal name="Segment(2)" />
        <signal name="Segment(1)" />
        <signal name="Segment(0)" />
        <signal name="clk" />
        <signal name="RST" />
        <port polarity="Input" name="HEXS(15:0)" />
        <port polarity="Input" name="LES(3:0)" />
        <port polarity="Input" name="points(3:0)" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="Segment(7:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Input" name="RST" />
        <blockdef name="clkdiv">
            <timestamp>2023-11-9T16:14:17</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="MC14495_SCH">
            <timestamp>2023-10-26T16:7:2</timestamp>
            <rect width="256" x="64" y="-512" height="512" />
            <line x2="0" y1="-480" y2="-480" x1="64" />
            <line x2="0" y1="-400" y2="-400" x1="64" />
            <line x2="0" y1="-320" y2="-320" x1="64" />
            <line x2="0" y1="-240" y2="-240" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-80" y2="-80" x1="64" />
            <line x2="384" y1="-480" y2="-480" x1="320" />
            <line x2="384" y1="-416" y2="-416" x1="320" />
            <line x2="384" y1="-352" y2="-352" x1="320" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="dispsyncv">
            <timestamp>2023-11-9T17:49:23</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="clkdiv" name="XLXI_1">
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="RST" name="rst" />
            <blockpin signalname="clkd(31:0)" name="clkdiv(31:0)" />
        </block>
        <block symbolname="MC14495_SCH" name="XLXI_6">
            <blockpin signalname="HEX(1)" name="D1" />
            <blockpin signalname="HEX(2)" name="D2" />
            <blockpin signalname="HEX(0)" name="D0" />
            <blockpin signalname="HEX(3)" name="D3" />
            <blockpin signalname="XLXN_13" name="LE" />
            <blockpin signalname="XLXN_12" name="point" />
            <blockpin signalname="Segment(7)" name="p" />
            <blockpin signalname="Segment(0)" name="a" />
            <blockpin signalname="Segment(1)" name="b" />
            <blockpin signalname="Segment(2)" name="c" />
            <blockpin signalname="Segment(3)" name="d" />
            <blockpin signalname="Segment(4)" name="e" />
            <blockpin signalname="Segment(5)" name="f" />
            <blockpin signalname="Segment(6)" name="g" />
        </block>
        <block symbolname="dispsyncv" name="XLXI_13">
            <blockpin signalname="HEXS(15:0)" name="Hexs(15:0)" />
            <blockpin signalname="clkd(18:17)" name="Scan(1:0)" />
            <blockpin signalname="points(3:0)" name="Point(3:0)" />
            <blockpin signalname="LES(3:0)" name="Les(3:0)" />
            <blockpin signalname="XLXN_12" name="p" />
            <blockpin signalname="XLXN_13" name="LE" />
            <blockpin signalname="HEX(3:0)" name="Hex(3:0)" />
            <blockpin signalname="AN(3:0)" name="AN(3:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="736" y="848" name="XLXI_1" orien="R0">
        </instance>
        <branch name="clkd(31:0)">
            <wire x2="1280" y1="960" y2="960" x1="800" />
            <wire x2="800" y1="960" y2="1184" x1="800" />
            <wire x2="800" y1="1184" y2="1200" x1="800" />
            <wire x2="1280" y1="752" y2="752" x1="1120" />
            <wire x2="1280" y1="752" y2="960" x1="1280" />
        </branch>
        <bustap x2="896" y1="1184" y2="1184" x1="800" />
        <branch name="clkd(18:17)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="904" y="1184" type="branch" />
            <wire x2="904" y1="1184" y2="1184" x1="896" />
            <wire x2="1136" y1="1184" y2="1184" x1="904" />
        </branch>
        <branch name="HEXS(15:0)">
            <wire x2="1136" y1="1120" y2="1120" x1="640" />
        </branch>
        <iomarker fontsize="28" x="640" y="1120" name="HEXS(15:0)" orien="R180" />
        <branch name="points(3:0)">
            <wire x2="1136" y1="1248" y2="1248" x1="640" />
        </branch>
        <iomarker fontsize="28" x="640" y="1248" name="points(3:0)" orien="R180" />
        <iomarker fontsize="28" x="640" y="1312" name="LES(3:0)" orien="R180" />
        <branch name="AN(3:0)">
            <wire x2="2560" y1="1312" y2="1312" x1="1520" />
        </branch>
        <branch name="Segment(7:0)">
            <wire x2="2480" y1="480" y2="560" x1="2480" />
            <wire x2="2480" y1="560" y2="624" x1="2480" />
            <wire x2="2480" y1="624" y2="688" x1="2480" />
            <wire x2="2480" y1="688" y2="752" x1="2480" />
            <wire x2="2480" y1="752" y2="816" x1="2480" />
            <wire x2="2480" y1="816" y2="880" x1="2480" />
            <wire x2="2480" y1="880" y2="944" x1="2480" />
            <wire x2="2480" y1="944" y2="1008" x1="2480" />
            <wire x2="2480" y1="1008" y2="1120" x1="2480" />
            <wire x2="2560" y1="1120" y2="1120" x1="2480" />
        </branch>
        <iomarker fontsize="28" x="2560" y="1120" name="Segment(7:0)" orien="R0" />
        <iomarker fontsize="28" x="2560" y="1312" name="AN(3:0)" orien="R0" />
        <bustap x2="1776" y1="800" y2="800" x1="1680" />
        <branch name="HEX(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1784" y="800" type="branch" />
            <wire x2="1784" y1="800" y2="800" x1="1776" />
            <wire x2="1856" y1="800" y2="800" x1="1784" />
        </branch>
        <bustap x2="1776" y1="640" y2="640" x1="1680" />
        <branch name="HEX(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1784" y="640" type="branch" />
            <wire x2="1784" y1="640" y2="640" x1="1776" />
            <wire x2="1856" y1="640" y2="640" x1="1784" />
        </branch>
        <bustap x2="1776" y1="560" y2="560" x1="1680" />
        <branch name="HEX(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1784" y="560" type="branch" />
            <wire x2="1784" y1="560" y2="560" x1="1776" />
            <wire x2="1856" y1="560" y2="560" x1="1784" />
        </branch>
        <bustap x2="1776" y1="720" y2="720" x1="1680" />
        <branch name="HEX(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1784" y="720" type="branch" />
            <wire x2="1784" y1="720" y2="720" x1="1776" />
            <wire x2="1856" y1="720" y2="720" x1="1784" />
        </branch>
        <bustap x2="2384" y1="560" y2="560" x1="2480" />
        <branch name="Segment(7)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="560" type="branch" />
            <wire x2="2376" y1="560" y2="560" x1="2240" />
            <wire x2="2384" y1="560" y2="560" x1="2376" />
        </branch>
        <bustap x2="2384" y1="1008" y2="1008" x1="2480" />
        <branch name="Segment(6)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="1008" type="branch" />
            <wire x2="2376" y1="1008" y2="1008" x1="2240" />
            <wire x2="2384" y1="1008" y2="1008" x1="2376" />
        </branch>
        <bustap x2="2384" y1="944" y2="944" x1="2480" />
        <branch name="Segment(5)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="944" type="branch" />
            <wire x2="2376" y1="944" y2="944" x1="2240" />
            <wire x2="2384" y1="944" y2="944" x1="2376" />
        </branch>
        <bustap x2="2384" y1="880" y2="880" x1="2480" />
        <branch name="Segment(4)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="880" type="branch" />
            <wire x2="2376" y1="880" y2="880" x1="2240" />
            <wire x2="2384" y1="880" y2="880" x1="2376" />
        </branch>
        <bustap x2="2384" y1="816" y2="816" x1="2480" />
        <branch name="Segment(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="816" type="branch" />
            <wire x2="2376" y1="816" y2="816" x1="2240" />
            <wire x2="2384" y1="816" y2="816" x1="2376" />
        </branch>
        <bustap x2="2384" y1="752" y2="752" x1="2480" />
        <branch name="Segment(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="752" type="branch" />
            <wire x2="2376" y1="752" y2="752" x1="2240" />
            <wire x2="2384" y1="752" y2="752" x1="2376" />
        </branch>
        <bustap x2="2384" y1="688" y2="688" x1="2480" />
        <branch name="Segment(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="688" type="branch" />
            <wire x2="2376" y1="688" y2="688" x1="2240" />
            <wire x2="2384" y1="688" y2="688" x1="2376" />
        </branch>
        <bustap x2="2384" y1="624" y2="624" x1="2480" />
        <branch name="Segment(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2376" y="624" type="branch" />
            <wire x2="2376" y1="624" y2="624" x1="2240" />
            <wire x2="2384" y1="624" y2="624" x1="2376" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="1840" y1="1120" y2="1120" x1="1520" />
            <wire x2="1856" y1="960" y2="960" x1="1840" />
            <wire x2="1840" y1="960" y2="1120" x1="1840" />
        </branch>
        <instance x="1856" y="1040" name="XLXI_6" orien="R0">
        </instance>
        <branch name="HEX(3:0)">
            <wire x2="1680" y1="1248" y2="1248" x1="1520" />
            <wire x2="1680" y1="560" y2="640" x1="1680" />
            <wire x2="1680" y1="640" y2="720" x1="1680" />
            <wire x2="1680" y1="720" y2="800" x1="1680" />
            <wire x2="1680" y1="800" y2="1248" x1="1680" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1760" y1="1184" y2="1184" x1="1520" />
            <wire x2="1760" y1="880" y2="1184" x1="1760" />
            <wire x2="1856" y1="880" y2="880" x1="1760" />
        </branch>
        <branch name="LES(3:0)">
            <wire x2="1136" y1="1312" y2="1312" x1="640" />
        </branch>
        <branch name="clk">
            <wire x2="736" y1="752" y2="752" x1="640" />
        </branch>
        <branch name="RST">
            <wire x2="736" y1="816" y2="816" x1="640" />
        </branch>
        <iomarker fontsize="28" x="640" y="752" name="clk" orien="R180" />
        <iomarker fontsize="28" x="640" y="816" name="RST" orien="R180" />
        <instance x="1136" y="1344" name="XLXI_13" orien="R0">
        </instance>
    </sheet>
</drawing>