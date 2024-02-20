<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="Co" />
        <signal name="A(3:0)" />
        <signal name="B(3:0)" />
        <signal name="XLXN_8" />
        <signal name="Ctrl" />
        <signal name="S(3:0)" />
        <signal name="A(3)" />
        <signal name="A(2)" />
        <signal name="A(1)" />
        <signal name="A(0)" />
        <signal name="B(3)" />
        <signal name="B(2)" />
        <signal name="B(1)" />
        <signal name="B(0)" />
        <signal name="XLXN_20" />
        <signal name="S(3)" />
        <signal name="S(2)" />
        <signal name="S(1)" />
        <signal name="S(0)" />
        <signal name="XLXN_25" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <port polarity="Output" name="Co" />
        <port polarity="Input" name="A(3:0)" />
        <port polarity="Input" name="B(3:0)" />
        <port polarity="Input" name="Ctrl" />
        <port polarity="Output" name="S(3:0)" />
        <blockdef name="AddSub1b">
            <timestamp>2023-11-9T23:53:1</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="AddSub1b" name="XLXI_1">
            <blockpin signalname="A(0)" name="A" />
            <blockpin signalname="Ctrl" name="Ci" />
            <blockpin signalname="B(0)" name="B" />
            <blockpin signalname="Ctrl" name="Ctrl" />
            <blockpin signalname="XLXN_1" name="Co" />
            <blockpin signalname="S(0)" name="S" />
        </block>
        <block symbolname="AddSub1b" name="XLXI_2">
            <blockpin signalname="A(1)" name="A" />
            <blockpin signalname="XLXN_1" name="Ci" />
            <blockpin signalname="B(1)" name="B" />
            <blockpin signalname="Ctrl" name="Ctrl" />
            <blockpin signalname="XLXN_2" name="Co" />
            <blockpin signalname="S(1)" name="S" />
        </block>
        <block symbolname="AddSub1b" name="XLXI_3">
            <blockpin signalname="A(2)" name="A" />
            <blockpin signalname="XLXN_2" name="Ci" />
            <blockpin signalname="B(2)" name="B" />
            <blockpin signalname="Ctrl" name="Ctrl" />
            <blockpin signalname="XLXN_3" name="Co" />
            <blockpin signalname="S(2)" name="S" />
        </block>
        <block symbolname="AddSub1b" name="XLXI_4">
            <blockpin signalname="A(3)" name="A" />
            <blockpin signalname="XLXN_3" name="Ci" />
            <blockpin signalname="B(3)" name="B" />
            <blockpin signalname="Ctrl" name="Ctrl" />
            <blockpin signalname="Co" name="Co" />
            <blockpin signalname="S(3)" name="S" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1776" y="816" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1776" y="1216" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1776" y="1616" name="XLXI_3" orien="R0">
        </instance>
        <instance x="1776" y="2016" name="XLXI_4" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="2240" y1="880" y2="880" x1="1680" />
            <wire x2="1680" y1="880" y2="1056" x1="1680" />
            <wire x2="1776" y1="1056" y2="1056" x1="1680" />
            <wire x2="2240" y1="592" y2="592" x1="2160" />
            <wire x2="2240" y1="592" y2="880" x1="2240" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="2240" y1="1280" y2="1280" x1="1680" />
            <wire x2="1680" y1="1280" y2="1456" x1="1680" />
            <wire x2="1776" y1="1456" y2="1456" x1="1680" />
            <wire x2="2240" y1="992" y2="992" x1="2160" />
            <wire x2="2240" y1="992" y2="1280" x1="2240" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="2240" y1="1680" y2="1680" x1="1680" />
            <wire x2="1680" y1="1680" y2="1856" x1="1680" />
            <wire x2="1776" y1="1856" y2="1856" x1="1680" />
            <wire x2="2240" y1="1392" y2="1392" x1="2160" />
            <wire x2="2240" y1="1392" y2="1680" x1="2240" />
        </branch>
        <branch name="Co">
            <wire x2="2640" y1="1792" y2="1792" x1="2160" />
        </branch>
        <branch name="A(3:0)">
            <wire x2="1120" y1="560" y2="560" x1="1040" />
            <wire x2="1120" y1="560" y2="640" x1="1120" />
            <wire x2="1120" y1="640" y2="800" x1="1120" />
            <wire x2="1120" y1="800" y2="960" x1="1120" />
            <wire x2="1120" y1="960" y2="1120" x1="1120" />
            <wire x2="1120" y1="1120" y2="1200" x1="1120" />
        </branch>
        <branch name="B(3:0)">
            <wire x2="1120" y1="1280" y2="1280" x1="1040" />
            <wire x2="1120" y1="1280" y2="1360" x1="1120" />
            <wire x2="1120" y1="1360" y2="1520" x1="1120" />
            <wire x2="1120" y1="1520" y2="1680" x1="1120" />
            <wire x2="1120" y1="1680" y2="1840" x1="1120" />
            <wire x2="1120" y1="1840" y2="1920" x1="1120" />
        </branch>
        <branch name="Ctrl">
            <wire x2="1600" y1="400" y2="400" x1="1040" />
            <wire x2="1600" y1="400" y2="656" x1="1600" />
            <wire x2="1776" y1="656" y2="656" x1="1600" />
            <wire x2="1600" y1="656" y2="784" x1="1600" />
            <wire x2="1776" y1="784" y2="784" x1="1600" />
            <wire x2="1600" y1="784" y2="1184" x1="1600" />
            <wire x2="1600" y1="1184" y2="1584" x1="1600" />
            <wire x2="1600" y1="1584" y2="1984" x1="1600" />
            <wire x2="1776" y1="1984" y2="1984" x1="1600" />
            <wire x2="1776" y1="1584" y2="1584" x1="1600" />
            <wire x2="1776" y1="1184" y2="1184" x1="1600" />
        </branch>
        <branch name="S(3:0)">
            <wire x2="2640" y1="800" y2="880" x1="2640" />
            <wire x2="2640" y1="880" y2="1040" x1="2640" />
            <wire x2="2640" y1="1040" y2="1200" x1="2640" />
            <wire x2="2640" y1="1200" y2="1360" x1="2640" />
            <wire x2="2640" y1="1360" y2="1440" x1="2640" />
        </branch>
        <iomarker fontsize="28" x="1040" y="400" name="Ctrl" orien="R180" />
        <iomarker fontsize="28" x="1040" y="560" name="A(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1040" y="1280" name="B(3:0)" orien="R180" />
        <iomarker fontsize="28" x="2640" y="800" name="S(3:0)" orien="R270" />
        <bustap x2="1216" y1="1120" y2="1120" x1="1120" />
        <branch name="A(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1224" y="1120" type="branch" />
            <wire x2="1224" y1="1120" y2="1120" x1="1216" />
            <wire x2="1424" y1="1120" y2="1120" x1="1224" />
            <wire x2="1424" y1="1120" y2="1792" x1="1424" />
            <wire x2="1776" y1="1792" y2="1792" x1="1424" />
        </branch>
        <bustap x2="1216" y1="960" y2="960" x1="1120" />
        <branch name="A(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="960" type="branch" />
            <wire x2="1232" y1="960" y2="960" x1="1216" />
            <wire x2="1248" y1="960" y2="960" x1="1232" />
            <wire x2="1392" y1="960" y2="960" x1="1248" />
            <wire x2="1392" y1="960" y2="1392" x1="1392" />
            <wire x2="1776" y1="1392" y2="1392" x1="1392" />
        </branch>
        <bustap x2="1216" y1="800" y2="800" x1="1120" />
        <branch name="A(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="800" type="branch" />
            <wire x2="1232" y1="800" y2="800" x1="1216" />
            <wire x2="1248" y1="800" y2="800" x1="1232" />
            <wire x2="1360" y1="800" y2="800" x1="1248" />
            <wire x2="1360" y1="800" y2="992" x1="1360" />
            <wire x2="1776" y1="992" y2="992" x1="1360" />
        </branch>
        <bustap x2="1216" y1="640" y2="640" x1="1120" />
        <branch name="A(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="640" type="branch" />
            <wire x2="1232" y1="640" y2="640" x1="1216" />
            <wire x2="1248" y1="640" y2="640" x1="1232" />
            <wire x2="1328" y1="640" y2="640" x1="1248" />
            <wire x2="1328" y1="592" y2="640" x1="1328" />
            <wire x2="1776" y1="592" y2="592" x1="1328" />
        </branch>
        <bustap x2="1216" y1="1840" y2="1840" x1="1120" />
        <branch name="B(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1840" type="branch" />
            <wire x2="1232" y1="1840" y2="1840" x1="1216" />
            <wire x2="1248" y1="1840" y2="1840" x1="1232" />
            <wire x2="1552" y1="1840" y2="1840" x1="1248" />
            <wire x2="1552" y1="1840" y2="1920" x1="1552" />
            <wire x2="1776" y1="1920" y2="1920" x1="1552" />
        </branch>
        <bustap x2="1216" y1="1680" y2="1680" x1="1120" />
        <branch name="B(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1680" type="branch" />
            <wire x2="1232" y1="1680" y2="1680" x1="1216" />
            <wire x2="1248" y1="1680" y2="1680" x1="1232" />
            <wire x2="1520" y1="1680" y2="1680" x1="1248" />
            <wire x2="1520" y1="1520" y2="1680" x1="1520" />
            <wire x2="1776" y1="1520" y2="1520" x1="1520" />
        </branch>
        <bustap x2="1216" y1="1520" y2="1520" x1="1120" />
        <branch name="B(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1520" type="branch" />
            <wire x2="1232" y1="1520" y2="1520" x1="1216" />
            <wire x2="1248" y1="1520" y2="1520" x1="1232" />
            <wire x2="1488" y1="1520" y2="1520" x1="1248" />
            <wire x2="1776" y1="1120" y2="1120" x1="1488" />
            <wire x2="1488" y1="1120" y2="1520" x1="1488" />
        </branch>
        <bustap x2="1216" y1="1360" y2="1360" x1="1120" />
        <branch name="B(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1360" type="branch" />
            <wire x2="1232" y1="1360" y2="1360" x1="1216" />
            <wire x2="1248" y1="1360" y2="1360" x1="1232" />
            <wire x2="1280" y1="1360" y2="1360" x1="1248" />
            <wire x2="1456" y1="1360" y2="1360" x1="1280" />
            <wire x2="1456" y1="720" y2="1360" x1="1456" />
            <wire x2="1776" y1="720" y2="720" x1="1456" />
        </branch>
        <iomarker fontsize="28" x="2640" y="1792" name="Co" orien="R0" />
        <bustap x2="2544" y1="1360" y2="1360" x1="2640" />
        <branch name="S(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2520" y="1360" type="branch" />
            <wire x2="2480" y1="1984" y2="1984" x1="2160" />
            <wire x2="2496" y1="1984" y2="1984" x1="2480" />
            <wire x2="2520" y1="1360" y2="1360" x1="2496" />
            <wire x2="2544" y1="1360" y2="1360" x1="2520" />
            <wire x2="2496" y1="1360" y2="1984" x1="2496" />
        </branch>
        <bustap x2="2544" y1="1200" y2="1200" x1="2640" />
        <branch name="S(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2520" y="1200" type="branch" />
            <wire x2="2320" y1="1584" y2="1584" x1="2160" />
            <wire x2="2448" y1="1584" y2="1584" x1="2320" />
            <wire x2="2448" y1="1200" y2="1584" x1="2448" />
            <wire x2="2496" y1="1200" y2="1200" x1="2448" />
            <wire x2="2520" y1="1200" y2="1200" x1="2496" />
            <wire x2="2544" y1="1200" y2="1200" x1="2520" />
        </branch>
        <bustap x2="2544" y1="1040" y2="1040" x1="2640" />
        <branch name="S(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2528" y="1040" type="branch" />
            <wire x2="2400" y1="1184" y2="1184" x1="2160" />
            <wire x2="2400" y1="1040" y2="1184" x1="2400" />
            <wire x2="2512" y1="1040" y2="1040" x1="2400" />
            <wire x2="2528" y1="1040" y2="1040" x1="2512" />
            <wire x2="2544" y1="1040" y2="1040" x1="2528" />
        </branch>
        <bustap x2="2544" y1="880" y2="880" x1="2640" />
        <branch name="S(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2528" y="880" type="branch" />
            <wire x2="2512" y1="784" y2="784" x1="2160" />
            <wire x2="2512" y1="784" y2="880" x1="2512" />
            <wire x2="2528" y1="880" y2="880" x1="2512" />
            <wire x2="2544" y1="880" y2="880" x1="2528" />
        </branch>
    </sheet>
</drawing>