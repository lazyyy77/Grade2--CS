<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A(3:0)" />
        <signal name="XLXN_2(3:0)" />
        <signal name="B(3:0)" />
        <signal name="XLXN_4(3:0)" />
        <signal name="C(3:0)" />
        <signal name="A(3)" />
        <signal name="A(2)" />
        <signal name="A(1)" />
        <signal name="A(0)" />
        <signal name="B(3)" />
        <signal name="B(2)" />
        <signal name="B(1)" />
        <signal name="B(0)" />
        <signal name="XLXN_6" />
        <signal name="C(3)" />
        <signal name="XLXN_8" />
        <signal name="C(2)" />
        <signal name="C(1)" />
        <signal name="C(0)" />
        <port polarity="Input" name="A(3:0)" />
        <port polarity="Input" name="B(3:0)" />
        <port polarity="Output" name="C(3:0)" />
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="B(0)" name="I0" />
            <blockpin signalname="A(0)" name="I1" />
            <blockpin signalname="C(0)" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_6">
            <blockpin signalname="B(1)" name="I0" />
            <blockpin signalname="A(1)" name="I1" />
            <blockpin signalname="C(1)" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_7">
            <blockpin signalname="B(2)" name="I0" />
            <blockpin signalname="A(2)" name="I1" />
            <blockpin signalname="C(2)" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_8">
            <blockpin signalname="B(3)" name="I0" />
            <blockpin signalname="A(3)" name="I1" />
            <blockpin signalname="C(3)" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="A(3:0)">
            <wire x2="1120" y1="1152" y2="1152" x1="1040" />
            <wire x2="1120" y1="1152" y2="1200" x1="1120" />
            <wire x2="1120" y1="1200" y2="1280" x1="1120" />
            <wire x2="1120" y1="1040" y2="1120" x1="1120" />
            <wire x2="1120" y1="1120" y2="1152" x1="1120" />
        </branch>
        <branch name="B(3:0)">
            <wire x2="1120" y1="1488" y2="1488" x1="1040" />
            <wire x2="1120" y1="1488" y2="1520" x1="1120" />
            <wire x2="1120" y1="1520" y2="1600" x1="1120" />
            <wire x2="1120" y1="1360" y2="1440" x1="1120" />
            <wire x2="1120" y1="1440" y2="1488" x1="1120" />
        </branch>
        <branch name="C(3:0)">
            <wire x2="2240" y1="1200" y2="1280" x1="2240" />
            <wire x2="2240" y1="1280" y2="1312" x1="2240" />
            <wire x2="2288" y1="1312" y2="1312" x1="2240" />
            <wire x2="2320" y1="1312" y2="1312" x1="2288" />
            <wire x2="2240" y1="1312" y2="1360" x1="2240" />
            <wire x2="2240" y1="1360" y2="1440" x1="2240" />
        </branch>
        <bustap x2="1216" y1="1280" y2="1280" x1="1120" />
        <branch name="A(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1280" type="branch" />
            <wire x2="1232" y1="1280" y2="1280" x1="1216" />
            <wire x2="1248" y1="1280" y2="1280" x1="1232" />
            <wire x2="1456" y1="1280" y2="1280" x1="1248" />
            <wire x2="1456" y1="1280" y2="1520" x1="1456" />
            <wire x2="1600" y1="1520" y2="1520" x1="1456" />
        </branch>
        <bustap x2="1216" y1="1200" y2="1200" x1="1120" />
        <branch name="A(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1200" type="branch" />
            <wire x2="1232" y1="1200" y2="1200" x1="1216" />
            <wire x2="1248" y1="1200" y2="1200" x1="1232" />
            <wire x2="1504" y1="1200" y2="1200" x1="1248" />
            <wire x2="1504" y1="1200" y2="1360" x1="1504" />
            <wire x2="1600" y1="1360" y2="1360" x1="1504" />
        </branch>
        <bustap x2="1216" y1="1120" y2="1120" x1="1120" />
        <branch name="A(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1120" type="branch" />
            <wire x2="1232" y1="1120" y2="1120" x1="1216" />
            <wire x2="1248" y1="1120" y2="1120" x1="1232" />
            <wire x2="1328" y1="1120" y2="1120" x1="1248" />
            <wire x2="1520" y1="1120" y2="1120" x1="1328" />
            <wire x2="1552" y1="1120" y2="1120" x1="1520" />
            <wire x2="1552" y1="1120" y2="1200" x1="1552" />
            <wire x2="1600" y1="1200" y2="1200" x1="1552" />
        </branch>
        <bustap x2="1216" y1="1040" y2="1040" x1="1120" />
        <branch name="A(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1040" type="branch" />
            <wire x2="1232" y1="1040" y2="1040" x1="1216" />
            <wire x2="1248" y1="1040" y2="1040" x1="1232" />
            <wire x2="1600" y1="1040" y2="1040" x1="1248" />
        </branch>
        <bustap x2="1216" y1="1600" y2="1600" x1="1120" />
        <branch name="B(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1600" type="branch" />
            <wire x2="1232" y1="1600" y2="1600" x1="1216" />
            <wire x2="1248" y1="1600" y2="1600" x1="1232" />
            <wire x2="1264" y1="1600" y2="1600" x1="1248" />
            <wire x2="1264" y1="1584" y2="1600" x1="1264" />
            <wire x2="1600" y1="1584" y2="1584" x1="1264" />
        </branch>
        <bustap x2="1216" y1="1520" y2="1520" x1="1120" />
        <branch name="B(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1520" type="branch" />
            <wire x2="1232" y1="1520" y2="1520" x1="1216" />
            <wire x2="1248" y1="1520" y2="1520" x1="1232" />
            <wire x2="1312" y1="1520" y2="1520" x1="1248" />
            <wire x2="1312" y1="1424" y2="1520" x1="1312" />
            <wire x2="1600" y1="1424" y2="1424" x1="1312" />
        </branch>
        <bustap x2="1216" y1="1440" y2="1440" x1="1120" />
        <branch name="B(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1440" type="branch" />
            <wire x2="1232" y1="1440" y2="1440" x1="1216" />
            <wire x2="1248" y1="1440" y2="1440" x1="1232" />
            <wire x2="1360" y1="1440" y2="1440" x1="1248" />
            <wire x2="1360" y1="1264" y2="1440" x1="1360" />
            <wire x2="1600" y1="1264" y2="1264" x1="1360" />
        </branch>
        <bustap x2="1216" y1="1360" y2="1360" x1="1120" />
        <branch name="B(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1232" y="1360" type="branch" />
            <wire x2="1232" y1="1360" y2="1360" x1="1216" />
            <wire x2="1248" y1="1360" y2="1360" x1="1232" />
            <wire x2="1408" y1="1360" y2="1360" x1="1248" />
            <wire x2="1408" y1="1104" y2="1360" x1="1408" />
            <wire x2="1600" y1="1104" y2="1104" x1="1408" />
        </branch>
        <bustap x2="2144" y1="1440" y2="1440" x1="2240" />
        <branch name="C(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2128" y="1440" type="branch" />
            <wire x2="2112" y1="1552" y2="1552" x1="1856" />
            <wire x2="2128" y1="1440" y2="1440" x1="2112" />
            <wire x2="2144" y1="1440" y2="1440" x1="2128" />
            <wire x2="2112" y1="1440" y2="1552" x1="2112" />
        </branch>
        <bustap x2="2144" y1="1360" y2="1360" x1="2240" />
        <branch name="C(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2128" y="1360" type="branch" />
            <wire x2="2112" y1="1392" y2="1392" x1="1856" />
            <wire x2="2128" y1="1360" y2="1360" x1="2112" />
            <wire x2="2144" y1="1360" y2="1360" x1="2128" />
            <wire x2="2112" y1="1360" y2="1392" x1="2112" />
        </branch>
        <bustap x2="2144" y1="1280" y2="1280" x1="2240" />
        <branch name="C(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2128" y="1280" type="branch" />
            <wire x2="2112" y1="1232" y2="1232" x1="1856" />
            <wire x2="2112" y1="1232" y2="1280" x1="2112" />
            <wire x2="2128" y1="1280" y2="1280" x1="2112" />
            <wire x2="2144" y1="1280" y2="1280" x1="2128" />
        </branch>
        <bustap x2="2144" y1="1200" y2="1200" x1="2240" />
        <branch name="C(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2128" y="1200" type="branch" />
            <wire x2="1872" y1="1072" y2="1072" x1="1856" />
            <wire x2="2112" y1="1072" y2="1072" x1="1872" />
            <wire x2="2112" y1="1072" y2="1200" x1="2112" />
            <wire x2="2128" y1="1200" y2="1200" x1="2112" />
            <wire x2="2144" y1="1200" y2="1200" x1="2128" />
        </branch>
        <iomarker fontsize="28" x="1040" y="1152" name="A(3:0)" orien="R180" />
        <iomarker fontsize="28" x="1040" y="1488" name="B(3:0)" orien="R180" />
        <iomarker fontsize="28" x="2320" y="1312" name="C(3:0)" orien="R0" />
        <instance x="1600" y="1168" name="XLXI_5" orien="R0" />
        <instance x="1600" y="1328" name="XLXI_6" orien="R0" />
        <instance x="1600" y="1488" name="XLXI_7" orien="R0" />
        <instance x="1600" y="1648" name="XLXI_8" orien="R0" />
    </sheet>
</drawing>