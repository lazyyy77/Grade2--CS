<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="s(1:0)" />
        <signal name="s(1)" />
        <signal name="s(0)" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_44" />
        <signal name="XLXN_45" />
        <signal name="I0(3:0)" />
        <signal name="I0(2)" />
        <signal name="I0(1)" />
        <signal name="I0(0)" />
        <signal name="I0(3)" />
        <signal name="I1(3:0)" />
        <signal name="XLXN_79" />
        <signal name="XLXN_81" />
        <signal name="XLXN_83" />
        <signal name="XLXN_85" />
        <signal name="XLXN_103" />
        <signal name="XLXN_105" />
        <signal name="XLXN_107" />
        <signal name="XLXN_109" />
        <signal name="XLXN_127" />
        <signal name="XLXN_129" />
        <signal name="XLXN_131" />
        <signal name="XLXN_133" />
        <signal name="XLXN_134" />
        <signal name="I2(3:0)" />
        <signal name="I3(3:0)" />
        <signal name="XLXN_156" />
        <signal name="XLXN_158" />
        <signal name="XLXN_160" />
        <signal name="XLXN_162" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_22" />
        <signal name="XLXN_23" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="XLXN_36" />
        <signal name="XLXN_37" />
        <signal name="XLXN_38" />
        <signal name="XLXN_39" />
        <signal name="XLXN_40" />
        <signal name="XLXN_41" />
        <signal name="XLXN_42" />
        <signal name="XLXN_43" />
        <signal name="XLXN_180" />
        <signal name="XLXN_182" />
        <signal name="XLXN_184" />
        <signal name="XLXN_186" />
        <signal name="I1(0)" />
        <signal name="I1(1)" />
        <signal name="I1(2)" />
        <signal name="I2(3)" />
        <signal name="I2(2)" />
        <signal name="I2(1)" />
        <signal name="I2(0)" />
        <signal name="I3(3)" />
        <signal name="I3(2)" />
        <signal name="I3(1)" />
        <signal name="I3(0)" />
        <signal name="I1(3)" />
        <signal name="XLXN_211" />
        <signal name="XLXN_212" />
        <signal name="XLXN_213" />
        <signal name="XLXN_214" />
        <signal name="o(3:0)" />
        <signal name="o(3)" />
        <signal name="o(2)" />
        <signal name="o(1)" />
        <signal name="o(0)" />
        <port polarity="Input" name="s(1:0)" />
        <port polarity="Input" name="I0(3:0)" />
        <port polarity="Input" name="I1(3:0)" />
        <port polarity="Input" name="I2(3:0)" />
        <port polarity="Input" name="I3(3:0)" />
        <port polarity="Output" name="o(3:0)" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="s(1)" name="I" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="s(0)" name="I" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="s(0)" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="s(0)" name="I1" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="I0(0)" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_20" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="I1(0)" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_21" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="I2(0)" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_22" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="I3(0)" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_11">
            <blockpin signalname="XLXN_23" name="I0" />
            <blockpin signalname="XLXN_22" name="I1" />
            <blockpin signalname="XLXN_21" name="I2" />
            <blockpin signalname="XLXN_20" name="I3" />
            <blockpin signalname="o(0)" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_17">
            <blockpin signalname="I0(1)" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_32" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_18">
            <blockpin signalname="I1(1)" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_33" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_19">
            <blockpin signalname="I2(1)" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_34" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_20">
            <blockpin signalname="I3(1)" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_35" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_21">
            <blockpin signalname="XLXN_35" name="I0" />
            <blockpin signalname="XLXN_34" name="I1" />
            <blockpin signalname="XLXN_33" name="I2" />
            <blockpin signalname="XLXN_32" name="I3" />
            <blockpin signalname="o(1)" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_22">
            <blockpin signalname="I0(2)" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_23">
            <blockpin signalname="I1(2)" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_37" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_24">
            <blockpin signalname="I2(2)" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_38" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_25">
            <blockpin signalname="I3(2)" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_39" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_26">
            <blockpin signalname="XLXN_39" name="I0" />
            <blockpin signalname="XLXN_38" name="I1" />
            <blockpin signalname="XLXN_37" name="I2" />
            <blockpin signalname="XLXN_36" name="I3" />
            <blockpin signalname="o(2)" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_27">
            <blockpin signalname="I0(3)" name="I0" />
            <blockpin signalname="XLXN_27" name="I1" />
            <blockpin signalname="XLXN_40" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_28">
            <blockpin signalname="I1(3)" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_41" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_29">
            <blockpin signalname="I2(3)" name="I0" />
            <blockpin signalname="XLXN_25" name="I1" />
            <blockpin signalname="XLXN_42" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_30">
            <blockpin signalname="I3(3)" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_43" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_31">
            <blockpin signalname="XLXN_43" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_41" name="I2" />
            <blockpin signalname="XLXN_40" name="I3" />
            <blockpin signalname="o(3)" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="7040" height="5440">
        <branch name="s(1:0)">
            <wire x2="560" y1="1200" y2="1200" x1="480" />
            <wire x2="560" y1="1200" y2="1264" x1="560" />
            <wire x2="560" y1="1264" y2="1280" x1="560" />
            <wire x2="560" y1="1120" y2="1136" x1="560" />
            <wire x2="560" y1="1136" y2="1200" x1="560" />
        </branch>
        <iomarker fontsize="28" x="480" y="1200" name="s(1:0)" orien="R180" />
        <bustap x2="656" y1="1136" y2="1136" x1="560" />
        <branch name="s(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="680" y="1136" type="branch" />
            <wire x2="680" y1="1136" y2="1136" x1="656" />
            <wire x2="880" y1="1136" y2="1136" x1="680" />
            <wire x2="960" y1="1136" y2="1136" x1="880" />
            <wire x2="880" y1="1136" y2="1504" x1="880" />
            <wire x2="1440" y1="1504" y2="1504" x1="880" />
            <wire x2="880" y1="1504" y2="1664" x1="880" />
            <wire x2="1440" y1="1664" y2="1664" x1="880" />
        </branch>
        <bustap x2="656" y1="1264" y2="1264" x1="560" />
        <instance x="960" y="1168" name="XLXI_1" orien="R0" />
        <instance x="960" y="1296" name="XLXI_2" orien="R0" />
        <instance x="1440" y="1248" name="XLXI_3" orien="R0" />
        <instance x="1440" y="1408" name="XLXI_4" orien="R0" />
        <instance x="1440" y="1568" name="XLXI_5" orien="R0" />
        <instance x="1440" y="1728" name="XLXI_6" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="1280" y1="1136" y2="1136" x1="1184" />
            <wire x2="1280" y1="1136" y2="1280" x1="1280" />
            <wire x2="1440" y1="1280" y2="1280" x1="1280" />
            <wire x2="1280" y1="1120" y2="1136" x1="1280" />
            <wire x2="1440" y1="1120" y2="1120" x1="1280" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1200" y1="1264" y2="1264" x1="1184" />
            <wire x2="1200" y1="1264" y2="1440" x1="1200" />
            <wire x2="1440" y1="1440" y2="1440" x1="1200" />
            <wire x2="1440" y1="1184" y2="1184" x1="1200" />
            <wire x2="1200" y1="1184" y2="1264" x1="1200" />
        </branch>
        <branch name="s(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="672" y="1264" type="branch" />
            <wire x2="672" y1="1264" y2="1264" x1="656" />
            <wire x2="800" y1="1264" y2="1264" x1="672" />
            <wire x2="960" y1="1264" y2="1264" x1="800" />
            <wire x2="800" y1="1264" y2="1328" x1="800" />
            <wire x2="816" y1="1328" y2="1328" x1="800" />
            <wire x2="816" y1="1328" y2="1344" x1="816" />
            <wire x2="1184" y1="1344" y2="1344" x1="816" />
            <wire x2="800" y1="1328" y2="1600" x1="800" />
            <wire x2="1440" y1="1600" y2="1600" x1="800" />
            <wire x2="1184" y1="1328" y2="1344" x1="1184" />
            <wire x2="1216" y1="1328" y2="1328" x1="1184" />
            <wire x2="1216" y1="1328" y2="1344" x1="1216" />
            <wire x2="1440" y1="1344" y2="1344" x1="1216" />
        </branch>
        <branch name="I0(3:0)">
            <wire x2="1920" y1="2464" y2="2464" x1="560" />
            <wire x2="1920" y1="2464" y2="3104" x1="1920" />
            <wire x2="1920" y1="1184" y2="1824" x1="1920" />
            <wire x2="1920" y1="1824" y2="2464" x1="1920" />
        </branch>
        <iomarker fontsize="28" x="560" y="2464" name="I0(3:0)" orien="R180" />
        <bustap x2="2016" y1="2464" y2="2464" x1="1920" />
        <branch name="I0(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2048" y="2464" type="branch" />
            <wire x2="2048" y1="2464" y2="2464" x1="2016" />
            <wire x2="2880" y1="2464" y2="2464" x1="2048" />
        </branch>
        <bustap x2="2016" y1="1824" y2="1824" x1="1920" />
        <branch name="I0(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2032" y="1824" type="branch" />
            <wire x2="2032" y1="1824" y2="1824" x1="2016" />
            <wire x2="2880" y1="1824" y2="1824" x1="2032" />
        </branch>
        <bustap x2="2016" y1="1184" y2="1184" x1="1920" />
        <branch name="I0(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2032" y="1184" type="branch" />
            <wire x2="2032" y1="1184" y2="1184" x1="2016" />
            <wire x2="2880" y1="1184" y2="1184" x1="2032" />
        </branch>
        <bustap x2="2016" y1="3104" y2="3104" x1="1920" />
        <branch name="I0(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2024" y="3104" type="branch" />
            <wire x2="2024" y1="3104" y2="3104" x1="2016" />
            <wire x2="2880" y1="3104" y2="3104" x1="2024" />
        </branch>
        <branch name="I1(3:0)">
            <wire x2="1776" y1="2624" y2="2624" x1="560" />
            <wire x2="1776" y1="2608" y2="2624" x1="1776" />
            <wire x2="1808" y1="2608" y2="2608" x1="1776" />
            <wire x2="1808" y1="2608" y2="2624" x1="1808" />
            <wire x2="2160" y1="2624" y2="2624" x1="1808" />
            <wire x2="2160" y1="2624" y2="3264" x1="2160" />
            <wire x2="2160" y1="1344" y2="1984" x1="2160" />
            <wire x2="2160" y1="1984" y2="2624" x1="2160" />
        </branch>
        <iomarker fontsize="28" x="560" y="2624" name="I1(3:0)" orien="R180" />
        <branch name="I2(3:0)">
            <wire x2="2400" y1="2784" y2="2784" x1="560" />
            <wire x2="2400" y1="2784" y2="3424" x1="2400" />
            <wire x2="2400" y1="2704" y2="2704" x1="2384" />
            <wire x2="2384" y1="2704" y2="2736" x1="2384" />
            <wire x2="2400" y1="2736" y2="2736" x1="2384" />
            <wire x2="2400" y1="2736" y2="2784" x1="2400" />
            <wire x2="2400" y1="1504" y2="2144" x1="2400" />
            <wire x2="2400" y1="2144" y2="2704" x1="2400" />
        </branch>
        <branch name="I3(3:0)">
            <wire x2="2640" y1="2944" y2="2944" x1="560" />
            <wire x2="2640" y1="2944" y2="3584" x1="2640" />
            <wire x2="2640" y1="1664" y2="2304" x1="2640" />
            <wire x2="2640" y1="2304" y2="2944" x1="2640" />
        </branch>
        <branch name="XLXN_20">
            <wire x2="3280" y1="1152" y2="1152" x1="3136" />
            <wire x2="3280" y1="1152" y2="1296" x1="3280" />
        </branch>
        <branch name="XLXN_21">
            <wire x2="3200" y1="1312" y2="1312" x1="3136" />
            <wire x2="3200" y1="1312" y2="1360" x1="3200" />
            <wire x2="3280" y1="1360" y2="1360" x1="3200" />
        </branch>
        <branch name="XLXN_22">
            <wire x2="3200" y1="1472" y2="1472" x1="3136" />
            <wire x2="3200" y1="1424" y2="1472" x1="3200" />
            <wire x2="3280" y1="1424" y2="1424" x1="3200" />
        </branch>
        <branch name="XLXN_23">
            <wire x2="3280" y1="1632" y2="1632" x1="3136" />
            <wire x2="3280" y1="1488" y2="1632" x1="3280" />
        </branch>
        <branch name="XLXN_32">
            <wire x2="3280" y1="1792" y2="1792" x1="3136" />
            <wire x2="3280" y1="1792" y2="1936" x1="3280" />
        </branch>
        <branch name="XLXN_33">
            <wire x2="3200" y1="1952" y2="1952" x1="3136" />
            <wire x2="3200" y1="1952" y2="2000" x1="3200" />
            <wire x2="3280" y1="2000" y2="2000" x1="3200" />
        </branch>
        <branch name="XLXN_34">
            <wire x2="3200" y1="2112" y2="2112" x1="3136" />
            <wire x2="3200" y1="2064" y2="2112" x1="3200" />
            <wire x2="3280" y1="2064" y2="2064" x1="3200" />
        </branch>
        <branch name="XLXN_35">
            <wire x2="3280" y1="2272" y2="2272" x1="3136" />
            <wire x2="3280" y1="2128" y2="2272" x1="3280" />
        </branch>
        <branch name="XLXN_36">
            <wire x2="3280" y1="2432" y2="2432" x1="3136" />
            <wire x2="3280" y1="2432" y2="2576" x1="3280" />
        </branch>
        <branch name="XLXN_37">
            <wire x2="3200" y1="2592" y2="2592" x1="3136" />
            <wire x2="3200" y1="2592" y2="2640" x1="3200" />
            <wire x2="3280" y1="2640" y2="2640" x1="3200" />
        </branch>
        <branch name="XLXN_38">
            <wire x2="3200" y1="2752" y2="2752" x1="3136" />
            <wire x2="3200" y1="2704" y2="2752" x1="3200" />
            <wire x2="3280" y1="2704" y2="2704" x1="3200" />
        </branch>
        <branch name="XLXN_39">
            <wire x2="3280" y1="2912" y2="2912" x1="3136" />
            <wire x2="3280" y1="2768" y2="2912" x1="3280" />
        </branch>
        <branch name="XLXN_40">
            <wire x2="3280" y1="3072" y2="3072" x1="3136" />
            <wire x2="3280" y1="3072" y2="3216" x1="3280" />
        </branch>
        <branch name="XLXN_41">
            <wire x2="3200" y1="3232" y2="3232" x1="3136" />
            <wire x2="3200" y1="3232" y2="3280" x1="3200" />
            <wire x2="3280" y1="3280" y2="3280" x1="3200" />
        </branch>
        <branch name="XLXN_42">
            <wire x2="3200" y1="3392" y2="3392" x1="3136" />
            <wire x2="3200" y1="3344" y2="3392" x1="3200" />
            <wire x2="3280" y1="3344" y2="3344" x1="3200" />
        </branch>
        <branch name="XLXN_43">
            <wire x2="3280" y1="3552" y2="3552" x1="3136" />
            <wire x2="3280" y1="3408" y2="3552" x1="3280" />
        </branch>
        <instance x="2880" y="1248" name="XLXI_7" orien="R0" />
        <instance x="2880" y="1568" name="XLXI_9" orien="R0" />
        <instance x="2880" y="1728" name="XLXI_10" orien="R0" />
        <instance x="3280" y="1552" name="XLXI_11" orien="R0" />
        <instance x="2880" y="1888" name="XLXI_17" orien="R0" />
        <instance x="2880" y="2208" name="XLXI_19" orien="R0" />
        <instance x="2880" y="2368" name="XLXI_20" orien="R0" />
        <instance x="3280" y="2192" name="XLXI_21" orien="R0" />
        <instance x="2880" y="2528" name="XLXI_22" orien="R0" />
        <instance x="2880" y="2688" name="XLXI_23" orien="R0" />
        <instance x="2880" y="2848" name="XLXI_24" orien="R0" />
        <instance x="2880" y="3008" name="XLXI_25" orien="R0" />
        <instance x="3280" y="2832" name="XLXI_26" orien="R0" />
        <instance x="2880" y="3168" name="XLXI_27" orien="R0" />
        <instance x="2880" y="3328" name="XLXI_28" orien="R0" />
        <instance x="2880" y="3488" name="XLXI_29" orien="R0" />
        <instance x="2880" y="3648" name="XLXI_30" orien="R0" />
        <instance x="3280" y="3472" name="XLXI_31" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="1760" y1="1632" y2="1632" x1="1696" />
            <wire x2="1760" y1="1632" y2="2240" x1="1760" />
            <wire x2="1760" y1="2240" y2="2880" x1="1760" />
            <wire x2="1760" y1="2880" y2="3520" x1="1760" />
            <wire x2="2880" y1="3520" y2="3520" x1="1760" />
            <wire x2="2880" y1="2880" y2="2880" x1="1760" />
            <wire x2="2880" y1="2240" y2="2240" x1="1760" />
            <wire x2="2880" y1="1600" y2="1600" x1="1760" />
            <wire x2="1760" y1="1600" y2="1632" x1="1760" />
        </branch>
        <branch name="XLXN_25">
            <wire x2="1792" y1="1472" y2="1472" x1="1696" />
            <wire x2="1792" y1="1472" y2="2080" x1="1792" />
            <wire x2="1792" y1="2080" y2="2720" x1="1792" />
            <wire x2="1792" y1="2720" y2="3360" x1="1792" />
            <wire x2="2880" y1="3360" y2="3360" x1="1792" />
            <wire x2="2880" y1="2720" y2="2720" x1="1792" />
            <wire x2="2880" y1="2080" y2="2080" x1="1792" />
            <wire x2="2880" y1="1440" y2="1440" x1="1792" />
            <wire x2="1792" y1="1440" y2="1472" x1="1792" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="1856" y1="1152" y2="1152" x1="1696" />
            <wire x2="1856" y1="1152" y2="1760" x1="1856" />
            <wire x2="1856" y1="1760" y2="2400" x1="1856" />
            <wire x2="1856" y1="2400" y2="3040" x1="1856" />
            <wire x2="2880" y1="3040" y2="3040" x1="1856" />
            <wire x2="2880" y1="2400" y2="2400" x1="1856" />
            <wire x2="2880" y1="1760" y2="1760" x1="1856" />
            <wire x2="2880" y1="1120" y2="1120" x1="1856" />
            <wire x2="1856" y1="1120" y2="1152" x1="1856" />
        </branch>
        <iomarker fontsize="28" x="560" y="2784" name="I2(3:0)" orien="R180" />
        <iomarker fontsize="28" x="560" y="2944" name="I3(3:0)" orien="R180" />
        <bustap x2="2256" y1="1344" y2="1344" x1="2160" />
        <branch name="I1(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2264" y="1344" type="branch" />
            <wire x2="2264" y1="1344" y2="1344" x1="2256" />
            <wire x2="2880" y1="1344" y2="1344" x1="2264" />
        </branch>
        <bustap x2="2256" y1="1984" y2="1984" x1="2160" />
        <branch name="I1(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2260" y="1984" type="branch" />
            <wire x2="2260" y1="1984" y2="1984" x1="2256" />
            <wire x2="2880" y1="1984" y2="1984" x1="2260" />
        </branch>
        <bustap x2="2256" y1="2624" y2="2624" x1="2160" />
        <branch name="I1(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2264" y="2624" type="branch" />
            <wire x2="2264" y1="2624" y2="2624" x1="2256" />
            <wire x2="2880" y1="2624" y2="2624" x1="2264" />
        </branch>
        <bustap x2="2256" y1="3264" y2="3264" x1="2160" />
        <bustap x2="2496" y1="3424" y2="3424" x1="2400" />
        <branch name="I2(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2504" y="3424" type="branch" />
            <wire x2="2504" y1="3424" y2="3424" x1="2496" />
            <wire x2="2880" y1="3424" y2="3424" x1="2504" />
        </branch>
        <bustap x2="2496" y1="2784" y2="2784" x1="2400" />
        <branch name="I2(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2508" y="2784" type="branch" />
            <wire x2="2508" y1="2784" y2="2784" x1="2496" />
            <wire x2="2880" y1="2784" y2="2784" x1="2508" />
        </branch>
        <bustap x2="2496" y1="2144" y2="2144" x1="2400" />
        <branch name="I2(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2504" y="2144" type="branch" />
            <wire x2="2504" y1="2144" y2="2144" x1="2496" />
            <wire x2="2880" y1="2144" y2="2144" x1="2504" />
        </branch>
        <bustap x2="2496" y1="1504" y2="1504" x1="2400" />
        <branch name="I2(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2504" y="1504" type="branch" />
            <wire x2="2504" y1="1504" y2="1504" x1="2496" />
            <wire x2="2880" y1="1504" y2="1504" x1="2504" />
        </branch>
        <bustap x2="2736" y1="3584" y2="3584" x1="2640" />
        <branch name="I3(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2744" y="3584" type="branch" />
            <wire x2="2744" y1="3584" y2="3584" x1="2736" />
            <wire x2="2880" y1="3584" y2="3584" x1="2744" />
        </branch>
        <bustap x2="2736" y1="2944" y2="2944" x1="2640" />
        <branch name="I3(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2744" y="2944" type="branch" />
            <wire x2="2744" y1="2944" y2="2944" x1="2736" />
            <wire x2="2880" y1="2944" y2="2944" x1="2744" />
        </branch>
        <bustap x2="2736" y1="2304" y2="2304" x1="2640" />
        <branch name="I3(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2744" y="2304" type="branch" />
            <wire x2="2744" y1="2304" y2="2304" x1="2736" />
            <wire x2="2880" y1="2304" y2="2304" x1="2744" />
        </branch>
        <bustap x2="2736" y1="1664" y2="1664" x1="2640" />
        <branch name="I3(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2744" y="1664" type="branch" />
            <wire x2="2744" y1="1664" y2="1664" x1="2736" />
            <wire x2="2880" y1="1664" y2="1664" x1="2744" />
        </branch>
        <branch name="XLXN_26">
            <wire x2="1824" y1="1312" y2="1312" x1="1696" />
            <wire x2="1824" y1="1312" y2="1920" x1="1824" />
            <wire x2="1824" y1="1920" y2="2560" x1="1824" />
            <wire x2="1824" y1="2560" y2="3200" x1="1824" />
            <wire x2="2880" y1="3200" y2="3200" x1="1824" />
            <wire x2="2880" y1="2560" y2="2560" x1="1824" />
            <wire x2="2880" y1="1920" y2="1920" x1="1824" />
            <wire x2="1824" y1="1280" y2="1312" x1="1824" />
            <wire x2="2880" y1="1280" y2="1280" x1="1824" />
        </branch>
        <instance x="2880" y="1408" name="XLXI_8" orien="R0" />
        <instance x="2880" y="2048" name="XLXI_18" orien="R0" />
        <branch name="I1(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2264" y="3264" type="branch" />
            <wire x2="2264" y1="3264" y2="3264" x1="2256" />
            <wire x2="2880" y1="3264" y2="3264" x1="2264" />
        </branch>
        <branch name="o(3:0)">
            <wire x2="4240" y1="1392" y2="2032" x1="4240" />
            <wire x2="4240" y1="2032" y2="2320" x1="4240" />
            <wire x2="4400" y1="2320" y2="2320" x1="4240" />
            <wire x2="4240" y1="2320" y2="2672" x1="4240" />
            <wire x2="4240" y1="2672" y2="3312" x1="4240" />
        </branch>
        <iomarker fontsize="28" x="4400" y="2320" name="o(3:0)" orien="R0" />
        <bustap x2="4144" y1="3312" y2="3312" x1="4240" />
        <branch name="o(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4136" y="3312" type="branch" />
            <wire x2="4136" y1="3312" y2="3312" x1="3536" />
            <wire x2="4144" y1="3312" y2="3312" x1="4136" />
        </branch>
        <bustap x2="4144" y1="2672" y2="2672" x1="4240" />
        <branch name="o(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4136" y="2672" type="branch" />
            <wire x2="4136" y1="2672" y2="2672" x1="3536" />
            <wire x2="4144" y1="2672" y2="2672" x1="4136" />
        </branch>
        <bustap x2="4144" y1="2032" y2="2032" x1="4240" />
        <branch name="o(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4136" y="2032" type="branch" />
            <wire x2="4136" y1="2032" y2="2032" x1="3536" />
            <wire x2="4144" y1="2032" y2="2032" x1="4136" />
        </branch>
        <bustap x2="4144" y1="1392" y2="1392" x1="4240" />
        <branch name="o(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="4136" y="1392" type="branch" />
            <wire x2="4136" y1="1392" y2="1392" x1="3536" />
            <wire x2="4144" y1="1392" y2="1392" x1="4136" />
        </branch>
    </sheet>
</drawing>